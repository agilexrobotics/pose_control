#!/bin/bash
source ~/.bashrc
password=agx

gnome-terminal -t "can" -- bash -c "echo $password | sudo -S slcand -o -f -s8 /dev/arxcan0 can0;sudo ifconfig can0 up;exec bash;"
sleep 1

gnome-terminal -t "can" -- bash -c "echo $password | sudo -S slcand -o -f -s8 /dev/arxcan0 can0;sudo ifconfig can0 up;exec bash;"
sleep 1
gnome-terminal -t "can" -- bash -c "echo $password | sudo -S slcand -o -f -s8 /dev/arxcan1 can1;sudo ifconfig can1 up;exec bash;"
sleep 1
gnome-terminal -t "can" -- bash -c "echo $password | sudo -S slcand -o -f -s8 /dev/arxcan2 can2;sudo ifconfig can2 up;exec bash;"
sleep 1
gnome-terminal -t "can" -- bash -c "echo $password | sudo -S slcand -o -f -s8 /dev/arxcan3 can3;sudo ifconfig can3 up;exec bash;"

sleep 1
gnome-terminal -t "can" -- bash -c "echo $password | sudo -S slcand -o -f -s6 /dev/arxcan4 can4;sudo ifconfig can4 up;exec bash;"






