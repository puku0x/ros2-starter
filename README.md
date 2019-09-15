# ROS2 Starter

## Prerequirements

- Ubuntu 18.04
- build-essential
- cmake
- git
- wget

```bash
$ sudo apt update
$ sudo apt install -y build-essential cmake git wget
```

## Install ROS2

```bash
$ ./install.sh
```

## Build
```bash
$ rosdep install --from-paths src --ignore-src -r -y
$ colcon build
```

## Run
```bash
$ . ./install/setup.bash
$ ros2 launch hello_world talker_listener.launch.py
```

## References
- [ros2 cheat sheet](https://github.com/artivis/ros2_cheats_sheet/blob/master/cli/cli_cheats_sheet.pdf)
```bash
# Examples
$ ros2 package create hello_world
$ ros2 run
$ ros2 topic
```
- [colcon doc](https://colcon.readthedocs.io)
```bash
# Examples
$ colcon build
$ colcon test
```
