#!/bin/bash
workspace=$(pwd)

source ~/.bashrc

gnome-terminal -t "master1" -x  bash -c "cd ${workspace}/master1; source devel/setup.bash && roslaunch arm_control L5.launch; exec bash;"
sleep 1
gnome-terminal -t "pos_follow1" -x  bash -c "cd ${workspace}/pos_follow1; source devel/setup.bash && roslaunch arm_control L5.launch; exec bash;"
sleep 1
gnome-terminal -t "master2" -x  bash -c "cd ${workspace}/master2; source devel/setup.bash && roslaunch arm_control L5.launch; exec bash;"
sleep 1
gnome-terminal -t "pos_follow2" -x  bash -c "cd ${workspace}/pos_follow2; source devel/setup.bash && roslaunch arm_control L5.launch; exec bash;"
