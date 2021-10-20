# WLED ROS Wrapper

![CI](https://github.com/ekampourakis/wled_ros_wrapper/workflows/CI/badge.svg)

## Overview

This is a simple C++ ROS wrapper for the WLED lighting controller.
It uses the HTTP API of the WLED controller to control the lighting.
Turning on and off the lights, changing the brightness, and changing the color of the lights are all possible.
Basic effect setting is also available.
Feel free to modify it to your needs.

**Keywords:** `wled`, `ros`, `wrapper`, `http`, `api`

![Thumbnail](.github/thumbnail.jpg)

## License 

The source code of this package is licensed under the [GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0.html) license.

**Author:** Manos Kampourakis
**Maintainer:** Manos Kampourakis

## Compatibility

This package has been tested on the following enviroment:

* Ubuntu 18.04
* ROS Melodic

It is possible for it to work on both newer and older versions of the above software, but it is not verified. Please update the documentation upon verification.

## Dependencies

This package only depends on ROS. If you don't already have ROS installed, follow [this guide](http://wiki.ros.org/melodic/Installation/Ubuntu/) for detailed instructions.

You can also install all the ROS package dependencies using `rosdep` inside your workspace: `rosdep install --from-paths src --ignore-src -r -y`

Check the GitHub actions for automated installation scripts.

## Compiling

* Clone this repository inside your source folder of your catkin workspace: `git clone https://github.com/ekampourakis/wled_ros_wrapper`
* Alternatively you can add this repository as a Git submodule in your existing project: `git submodule add https://github.com/ekampourakis/wled_ros_wrapper`
* Build the package: `catkin build wled_ros_wrapper`

## Running

After sourcing your catkin workspace, you can run: `roslaunch wled_ros_wrapper default.launch` to start the node.
You can also use the launch file parameters:

* `config`: Default `$(find wled_ros_wrapper)/config/default.yaml`. Loads the provided configuration file to the ROS parameter server.

## Configuring

Use the `config/default.yaml` configuration file to tune the settings of the node based on your needs.

## Interfacing

This package uses the standard ROS interfaces.

### Subscribers

* `set`: `wled_ros_wrapper::WLED`. The subscriber of wrapper. Used to set the LED strips.

### Publishers

None

### Services

None

## Troubleshooting

Here are some common bugs that were encountered during the development phase.