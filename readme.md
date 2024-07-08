# 1 环境配置

~~~python
# 1 删除编译的中间文件
./tools/delete_build_file.sh

# 2 编译每个机械臂工作空间
./tools/build.sh
~~~



# 2 关节角度joint_state控制
~~~python
# 1 第一次开启启动都需要can使能, 运行下面脚本，如果重启电脑，还需要运行该脚本
./tools/can.sh

# 2. 启动遥操作, 启动前需要关闭一切控制机器臂的程序
./tools/remote.sh

# 3. 启动从臂, 启动前需要关闭一切控制机器臂的程序
./tools/puppet.sh

# 4 启动任意臂
请参考./tools/remote.sh与./tools/puppet.sh脚本自行修改
~~~


# 3 末端姿态tip pose控制

~~~python
# 1 第一次开启启动都需要can使能, 运行下面脚本，如果重启电脑，还需要运行该脚本
./tools/can.sh

# 2. 启动遥操作, 启动前需要关闭一切控制机器臂的程序
./tools/pos_remote.sh

# 3. 启动从臂, 启动前需要关闭一切控制机器臂的程序
./tools/pos_puppet.sh

# 4 启动任意臂
请参考./tools/pos_remote.sh与./tools/pos_puppet.sh脚本自行修改
~~~

# 4 ros消息类型说明

1. 关节角度joint_state
`JointControl.msg`与`JointInformation.msg`
~~~python
float32[7] joint_pos   # 角度 0-5维为每个关节的角度(rad)，第6维为gripper(取值0-5, 映射到0-85mm)
float32[7] joint_vel   # 速度
float32[7] joint_cur   # 扭矩
int32 mode
~~~

2. Tip Pose

`PosCmd.msg`
+ 以零位姿态link6为固定坐标系原点
~~~python
# xyz单位m, rpy单位rad，gripper(取值0-5, 映射到0-85mm)
float64 x                  
float64 y
float64 z
float64 roll
float64 pitch
float64 yaw
float64 gripper
int32 mode1
int32 mode2
~~~

3. 坐标系示意图

+ 以零位姿态link6为固定坐标系原点
+ 零位示意图
<p align="center">
  <img src="./tools/3.jpg" width="480" height="360" />
  &nbsp;
  <img src="./tools/4.jpg" width="480" height="360" />
</p>

+ 空间某位置
<p align="center">
  <img src="./tools/1.jpg" width="480" height="360" />
  &nbsp;
  <img src="./tools/2.jpg" width="480" height="360" />
</p>

