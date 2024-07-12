# 1 环境编译

~~~python
# 1 进入该目录
cd pose_control

# 2 删除编译的中间文件
./tools/delete_build_file.sh

# 3 编译每个机械臂工作空间
./tools/build.sh
~~~


# 2 消息类型

## 2.1 消息类型说明
1. 末端姿态tip pose和关节状态joint_state消息类型说明
~~~python
# 1 joint_state关节角度： sensor_msgs::JointState
std_msgs/Header header
  uint32 seq
  time stamp              # 时间戳
  string frame_id        
string[] name             # 关节名字
float64[] position        # 关节位置（电机转角） 单位rad
float64[] velocity        # 关节速度
float64[] effort          # 关节扭矩

# 2 末端姿态tip pose ： geometry_msgs/PoseStamped
std_msgs/Header header
  uint32 seq
  time stamp              # 时间戳
  string frame_id         
geometry_msgs/Pose pose
  geometry_msgs/Point position
    float64 x             # x     单位m
    float64 y             # y     单位m
    float64 z             # z     单位m
  geometry_msgs/Quaternion orientation
    float64 x             # roll   单位rad
    float64 y             # pitch  单位rad
    float64 z             # yaw    单位rad
    float64 w             # gripper  
~~~

## 2.2 cobot_magic具体消息名称如下
1. sensor_msgs::JointState

+ 消息名称共4个：右主臂关节状态`/master/joint_right`, 左主臂关节状态`/master/joint_left`, 右从臂关节状态`/puppet/joint_right`, 左从臂关节状态`/puppet/joint_left` 

+ `/master/joint_right`内容如下：
~~~python
# ros打印消息内容命令：
# rostopic echo 话题名称
rostopic echo /master/joint_right

# 显示如下
header: 
  seq: 19616
  stamp:                   # 时间戳
    secs: 1720775569
    nsecs: 697398876
  frame_id: ''
name:                       # 名称
  - joint0
  - joint1
  - joint2
  - joint3
  - joint4
  - joint5
  - joint6                 # gripper
position: [0.2557792663574219, 1.796177864074707, 1.2426567077636719, -0.5769815444946289, -0.01125335693359375, 0.041008949279785156, 3.005075454711914]        # 转角
velocity: [-0.010990142822265625, -2.7802200317382812, 1.0879135131835938, -0.09889984130859375, -0.03296661376953125, -0.03296661376953125, -0.010990142822265625]    # 速度
effort: [-0.013187408447265625, -6.632966995239258, 5.006593704223633, 1.8241748809814453, -0.013187408447265625, -0.013187408447265625, -0.013187408447265625]  # 扭矩
~~~

2. geometry_msgs::PoseStamped

+ 消息名称共4个：右主臂末端姿态`/master/end_right`，左主臂末端姿态`/master/end_left`, 右从臂末端姿态`/puppet/end_right`, 左从臂末端姿态`/puppet/end_left`

+ 左从臂末端姿态`/puppet/end_left`内容如下：
+ **这里注意,使用了四元素的w分量来存储的gripper的数值**

~~~python
header: 
  seq: 21378
  stamp:                         # 时间戳
    secs: 1720775578
    nsecs: 507354757
  frame_id: ''
pose: 
  position: 
    x: -0.0017316965386271477   # x
    y: -0.004632180090993643    # y
    z: -0.008783199824392796    # z
  orientation: 
    x: -0.014360900036990643    # roll
    y: 0.15038831532001495      # pitch
    z: 0.008544730953872204     # yaw
    w: -0.01049041748046875     # gripper
~~~

## 2.3 **tip pose坐标系说明**


+ **以零位姿态link6为原点的固定坐标系**

+ 零位示意图

<p align="center">
  <img src="./doc/3.jpg" width="480" height="360" />
  &nbsp;
  <img src="./doc/4.jpg" width="480" height="360" />
</p>

+ 空间某位置

<p align="center">
  <img src="./doc/1.jpg" width="480" height="360" />
  &nbsp;
  <img src="./doc/2.jpg" width="480" height="360" />
</p>



# 3 遥操作

## 3.1 joint_state控制

~~~python
# 以下脚本在pose_control目录下进行

# 1 第一次开启启动都需要can使能, 运行下面脚本，如果重启电脑，还需要运行该脚本
./tools/can.sh

# 2. 启动遥操作, 启动前需要关闭一切控制机械臂的程序， 采集数据使用该脚本
./tools/remote.sh

# 3. 启动从臂, 启动前需要关闭一切控制机械臂的程序， 推理使用该脚本
./tools/puppet.sh

# 4 启动任意臂
请参考./tools/remote.sh与./tools/puppet.sh脚本自行修改
~~~

## 3.2 tip pose控制


~~~python
# 以下脚本在remote_control_pos目录下进行

# 1 第一次开启启动都需要can使能, 运行下面脚本，如果重启电脑，还需要运行该脚本
./tools/can.sh

# 2. 启动遥操作, 启动前需要关闭一切控制机械臂的程序， 采集数据使用该脚本
./tools/pos_remote.sh

# 3. 启动从臂, 启动前需要关闭一切控制机械臂的程序, 推理使用该脚本
./tools/pos_puppet.sh

# 4 启动任意臂
请参考./tools/pos_remote.sh与./tools/pos_puppet.sh脚本自行修改
~~~


# 4 订阅与发布消息代码样例

## 4.2 订阅

1. 订阅`sensor_msgs::JointState`类型：右主臂关节状态`/master/joint_right`,

~~~python
#!/home/lin/software/miniconda3/envs/aloha/bin/python
#coding=utf-8
import rospy
from sensor_msgs.msg import JointState

# 保存函数
def save_data(data):
    pass

# 回调函数
def callback(msg):
    print(msg)
    # print(msg.position)
    # print(msg.velocity)
    # print(msg.effort)
    save_data(msg.position)  # 保存需自定义

# 主函数创建订阅者
if __name__ == "__main__":
    rospy.init_node("ros_node") 
    rospy.loginfo("start...")
    topic_name = "/master/joint_right"
    sub = rospy.Subscriber(topic_name, JointState, callback)
    rospy.spin()  
~~~

2. 订阅`geometry_msgs::PoseStamped`类型：右主臂关节状态`/master/end_right`,

~~~python
#!/home/lin/software/miniconda3/envs/aloha/bin/python
#coding=utf-8
import rospy
from geometry_msgs.msg import PoseStamped

# 保存函数
def save_data(data):
    pass

# 回调函数
def callback(msg):
    print(msg)
    save_data(msg)  # 保存需自定义

# 主函数创建发布者
if __name__ == "__main__":
    rospy.init_node("ros_node") 
    rospy.loginfo("start...")
    topic_name = "/master/end_right"
    sub = rospy.Subscriber(topic_name, PoseStamped, callback)
    rospy.spin()   
~~~

# 4.2 发布消息

1. 发布`sensor_msgs::JointState`类型：右主臂关节状态`/master/joint_right`,
~~~python
#!/home/lin/software/miniconda3/envs/aloha/bin/python
#coding=utf-8
import rospy
from sensor_msgs.msg import JointState

if __name__ == "__main__":
    rospy.init_node("ros_node") 
    rospy.loginfo("start...")
    topic_name = "/master/joint_right"
    pub = rospy.Publisher(topic_name, JointState, queue_size=10) # 创建发布器
    rate = rospy.Rate(30)
    while not rospy.is_shutdown():
        msg = JointState()
        # 消息赋值
        msg.header.stamp = rospy.Time.now()
        msg.name = ['joint0', 'joint1','joint2', 'joint3', 'joint4', 'joint5','joint6']  
        msg.position = [1.0, 0.5, 0.2, 1.0, 0.5, 0.2, 0.3] 
        msg.velocity = [1.0, 0.5, 0.2, 1.0, 0.5, 0.2, 0.3] 
        msg.effort = [1.0, 0.5, 0.2, 1.0, 0.5, 0.2, 0.3] 
        
        rospy.loginfo(msg)  # 打印消息
        pub.publish(msg)    # 发布消息
        rate.sleep()
~~~



2. 发布`geometry_msgs::PoseStamped`类型：右主臂关节状态`/master/end_right`,

~~~python
#!/home/lin/software/miniconda3/envs/aloha/bin/python
#coding=utf-8
import rospy
from geometry_msgs.msg import PoseStamped

if __name__ == "__main__":
    rospy.init_node("ros_node") 
    rospy.loginfo("start...")
    topic_name = "/master/end_right"
    pub = rospy.Publisher(topic_name, PoseStamped, queue_size=10) # 创建发布器
    rate = rospy.Rate(30)
    while not rospy.is_shutdown():
        msg = PoseStamped()
        msg.header.stamp = rospy.Time.now()
        msg.pose.orientation.x = 1
        msg.pose.orientation.y = 0
        msg.pose.orientation.z = 0
        msg.pose.orientation.w = 0
        msg.pose.position.x = 1
        msg.pose.position.y = 1
        msg.pose.position.z = 1
        rospy.loginfo(msg)       # 打印消息
        pub.publish(msg)         # 发布消息
        rate.sleep()
~~~
