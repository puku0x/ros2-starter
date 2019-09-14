```bash
$ sudo locale-gen ja_JP ja_JP.UTF-8
$ sudo update-locale LC_ALL=ja_JP.UTF-8 lang=ja_JP.UTF-8
$ export LOCALE=ja_JP.UTF-8
```

```bash
$ sudo apt update
$ sudo apt install curl gnupg2 lsb-release -y
$ curl http://repo.ros2.org/repos.key | sudo apt-key add -
$ sudo sh -c 'echo "deb [arch=amd64,arm64] http://packages.ros.org/ros2/ubuntu `lsb_release -cs` $ $ main" > /etc/apt/sources.list.d/ros2-latest.list'
$ sudo apt update
```

```bash
$ export ROS_DISTRO=dashing
```

```bash
$ sudo apt install ros-$ROS_DISTRO-desktop -y
$ sudo apt install python3-colcon-common-extensions python3-rosdep python3-argcomplete -y

```

```bash
$ sudo rosdep init
$ rosdep update
```

```bash
$ echo "source /opt/ros/$ROS_DISTRO/setup.bash" >> ~/.bashrc
```
