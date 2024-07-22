# 1 同时发布joint_state与tip pose

1. 启动遥操作
~~~python
# 第一运行需要运行./tools/can.sh
./tools/remote.sh
~~~

2. joint_state控制puppet
~~~python
./tools/puppet.sh
~~~

3. tip pose控制puppet
~~~python
./tools/pos_puppet.sh
~~~


详细ros消息[参考链接](https://github.com/agilexrobotics/pose_control/blob/beta/readme.md)
