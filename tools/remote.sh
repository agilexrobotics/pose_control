#!/bin/bash
workspace=$(pwd)



 gnome-terminal -t "master1" -- bash -c "cd ${workspace}/master1; source devel/setup.bash && roslaunch arm_control L5.launch; exec bash;"
 sleep 1
 gnome-terminal -t "follow1" -- bash -c "cd ${workspace}/follow1; source devel/setup.bash && roslaunch arm_control L5.launch; exec bash;"
 sleep 1
 gnome-terminal -t "master2" -- bash -c "cd ${workspace}/master2; source devel/setup.bash && roslaunch arm_control L5.launch; exec bash;"
 sleep 1
 gnome-terminal -t "follow2" -- bash -c "cd ${workspace}/follow2; source devel/setup.bash && roslaunch arm_control L5.launch; exec bash;"



