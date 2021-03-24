/**
 * Created by kotaru on 3/24/21.
 * https://answers.ros.org/question/217960/how-to-write-a-thread-in-ros/
 *
 */

#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <boost/thread/thread.hpp>

void do_stuff(const int *publish_rate) {
  ros::NodeHandlePtr node = boost::make_shared<ros::NodeHandle>();
  ros::Publisher pub_b = node->advertise<std_msgs::Empty>("topic_b", 10);

  ros::Rate loop_rate(*publish_rate);
  double prev_time, curr_time, dt;
  prev_time = ros::Time::now().toSec();
  while (ros::ok()) {
    curr_time = ros::Time::now().toSec();
    dt = curr_time-prev_time;
    prev_time = curr_time;
    ROS_WARN("outer loop: %f", 1/dt);

    std_msgs::Empty msg;
    pub_b.publish(msg);
    loop_rate.sleep();
  }
}

int main(int argc, char **argv) {
  int rate_b = 100; // 1 Hz

  ros::init(argc, argv, "mt_node");

  // spawn another thread
  boost::thread thread_b(do_stuff, &rate_b);

  ros::NodeHandlePtr node = boost::make_shared<ros::NodeHandle>();
  ros::Publisher pub_a = node->advertise<std_msgs::Empty>("topic_a", 10);

  ros::Rate loop_rate(800); // 10 Hz
  double prev_time, curr_time, dt;
  prev_time = ros::Time::now().toSec();
  while (ros::ok()) {
    curr_time = ros::Time::now().toSec();
    dt = curr_time-prev_time;
    prev_time = curr_time;
    ROS_INFO("inner loop: %f", 1/dt);

    std_msgs::Empty msg;
    pub_a.publish(msg);
    loop_rate.sleep();

    // process any incoming messages in this thread
    ros::spinOnce();
  }

  // wait the second thread to finish
  thread_b.join();

  return 0;
}
