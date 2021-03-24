//
// Created by kotaru on 3/12/21.
//
#include <iostream>
#include <ros/ros.h>
#include <string>
#include <unistd.h>
#include <thread>

class RosTimerTest {
protected:
  ros::NodeHandle &nh_;
  ros::Timer timer1, timer2;

public:
  explicit RosTimerTest(ros::NodeHandle &_nh) : nh_(_nh) { init(); }
  ~RosTimerTest() = default;
  void init() {
    timer1 = timer1 = nh_.createTimer(ros::Duration(1.0 / 100),
                                      &RosTimerTest::function1, this);
    timer2 = nh_.createTimer(ros::Duration(1.0 / 500), &RosTimerTest::function2,
                             this);
  }
  void run() {}

  void function1(const ros::TimerEvent &event) {
    ROS_INFO("FUNCTION 1, dt: %f",
             (event.current_real.toSec() - event.last_real.toSec()));
    int j =0;
    for(int i = 0; i< 400000000; i++) {
      j++;
    };
  }
  void function2(const ros::TimerEvent &event) {
    ROS_INFO("ros tutorial function 2, dt: %f",
             (event.current_real.toSec() - event.last_real.toSec()));
    usleep(2.1);
  }
};

class RosDobleNodesTest {
protected:
private:

};



int main(int argc, char *argv[]) {
  ROS_INFO("Initializing ros_tutorial_node!");
  ros::init(argc, argv, "ros_tutorial_node");
  ros::NodeHandle nh_("high_freq");

//  RosTimerTest ros_tutorial_(nh_);
//  ros::spin();


  return 1;
}
