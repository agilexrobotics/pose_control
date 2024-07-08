#!/bin/bash
source ~/.bashrc

workspace=$(pwd)

sleep 1

gnome-terminal -t "can" -x bash -c "source ~/.bashrc;source /opt/ros/noetic/setup.bash;echo 123 | sudo -S sudo ip link set up can3 type can bitrate 1000000;candump can3;exec bash;"

sleep 1

gnome-terminal -t "launcher" -x bash -c "source ~/.bashrc;\
cd ${workspace};\
source devel/setup.bash;roslaunch arm_control arx5.launch;exec bash;"




