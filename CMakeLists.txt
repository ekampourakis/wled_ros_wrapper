cmake_minimum_required(VERSION 3.10.0)
project(wled_ros_wrapper)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -std=c++14 -march=native -Wextra -Wno-unknown-pragmas -g3 -O0 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -std=c++14 -march=native -Wextra -Wno-unknown-pragmas -g0 -Ofast")
IF(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
ENDIF(NOT CMAKE_BUILD_TYPE)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	message("Building ${PROJECT_NAME} in debug mode. Consider switching to an optimized build before releasing.")
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

find_package(catkin REQUIRED COMPONENTS
	roscpp
	message_generation
	message_runtime
	std_msgs
)

add_message_files(DIRECTORY msg)
# add_service_files(DIRECTORY srv)
generate_messages(DEPENDENCIES std_msgs)

catkin_package(CATKIN_DEPENDS
	roscpp
	message_generation
	message_runtime
	std_msgs
)

include_directories(${catkin_INCLUDE_DIRS} include)
set(SOURCES src/wrapper.cpp)
add_executable(wrapper ${SOURCES})
target_compile_options(wrapper PRIVATE)
target_link_libraries(wrapper ${catkin_LIBRARIES})
add_dependencies(wrapper ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS} ${PROJECT_NAME}_generate_messages_cpp)
install(DIRECTORY include/${PROJECT_NAME}/ DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})