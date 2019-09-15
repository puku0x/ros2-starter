# Set ROS2 distribution
export ROS_DISTRO=dashing

# Change locale
sudo locale-gen ja_JP ja_JP.UTF-8
sudo update-locale LC_ALL=ja_JP.UTF-8 lang=ja_JP.UTF-8
export LOCALE=ja_JP.UTF-8

# Prepare
sudo apt update
sudo apt install -y curl gnupg2 lsb-release
curl http://repo.ros2.org/repos.key | sudo apt-key add -
sudo sh -c 'echo "deb [arch=amd64,arm64] http://packages.ros.org/ros2/ubuntu `lsb_release -cs` main" > /etc/apt/sources.list.d/ros2-latest.list'
sudo apt update

# Install ROS2
sudo apt install -y ros-$ROS_DISTRO-desktop
sudo apt install -y python3-pip python3-colcon-common-extensions python3-rosdep python3-argcomplete

# Update dependencies
sudo rosdep init
rosdep update

# Add setup script
echo "source /opt/ros/$ROS_DISTRO/setup.bash" >> ~/.bashrc
