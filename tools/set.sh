#!/bin/bash
workspace=$(pwd)

sudo cp ${workspace}/tools/arx_can.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger

