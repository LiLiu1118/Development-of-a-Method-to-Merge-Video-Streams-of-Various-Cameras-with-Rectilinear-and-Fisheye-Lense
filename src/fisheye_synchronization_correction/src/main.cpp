#include "fisheye_synchronization_correction/fisheye_correction.h"
#include "fisheye_synchronization_correction/load_data.h"
#include <ros/ros.h>
#include <stdio.h>
#include <string>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <sensor_msgs/Image.h>

using namespace cv;
using namespace sensor_msgs;
using namespace message_filters;
using namespace std;

/**
 * This script uses ROS framework to realize fisheye camera image synchronization and correction.
 * Many standard ROS Class are used, for detail please refer to ROS.org
 */

// callback function used to process the subscribed messages.
void callback(const sensor_msgs::ImageConstPtr &msg_fisheye_left, const sensor_msgs::ImageConstPtr &msg_fisheye_middle, const sensor_msgs::ImageConstPtr &msg_fisheye_right)
{
  static int i = 0;
  std::ostringstream string_fisheye_left;
  std::ostringstream string_fisheye_middle;
  std::ostringstream string_fisheye_right;

  // cv_bridge translates ros messages to Mat.
  Mat fisheye_left = cv_bridge::toCvShare(msg_fisheye_left, "bgr8")->image;
  Mat fisheye_middle = cv_bridge::toCvShare(msg_fisheye_middle, "bgr8")->image;
  Mat fisheye_right = cv_bridge::toCvShare(msg_fisheye_right, "bgr8")->image;

  // use fisheye_correction function to correct fisheye image.
  vector<Mat> calibration_data_left = load_data("./camera_calibration/fisheye_left.yaml");
  Mat fisheye_left_rec = fisheye_correction(fisheye_left, calibration_data_left[0], calibration_data_left[1]);

  vector<Mat> calibration_data_middle = load_data("./camera_calibration/fisheye_middle.yaml");
  Mat fisheye_middle_rec = fisheye_correction(fisheye_middle, calibration_data_middle[0], calibration_data_middle[1]);

  vector<Mat> calibration_data_right = load_data("./camera_calibration/fisheye_right.yaml");
  Mat fisheye_right_rec = fisheye_correction(fisheye_right, calibration_data_right[0], calibration_data_right[1]);

  // show corrected fisheye images.
  cv::imshow("fisheye_left", fisheye_left_rec);
  cv::imshow("fisheye_middle", fisheye_middle_rec);
  cv::imshow("fisheye_right", fisheye_right_rec);
  cv::waitKey(1);

  // display the original timestamps of images.
  cout << "timestamp of fisheye_left: " << msg_fisheye_left->header.stamp << "\n"
       << endl;
  cout << "timestamp of fisheye_middle: " << msg_fisheye_middle->header.stamp << "\n"
       << endl;
  cout << "timestamp of fisheye_right: " << msg_fisheye_right->header.stamp << "\n"
       << endl;

  // write the sequence number of images to the string, which will be their filename when the are saved.
  string_fisheye_left << "/home/hans/Desktop/6_images/" << i << "_fisheye_left_rec.jpg";
  string_fisheye_middle << "/home/hans/Desktop/6_images/" << i << "_fisheye_middle_rec.jpg";
  string_fisheye_right << "/home/hans/Desktop/6_images/" << i << "_fisheye_right_rec.jpg";

  // save the corrected images.
  cv::imwrite(string_fisheye_left.str(), fisheye_left_rec);
  cout << string_fisheye_left.str() << " was written" << endl;
  cv::imwrite(string_fisheye_middle.str(), fisheye_middle_rec);
  cout << string_fisheye_middle.str() << " was written" << endl;
  cv::imwrite(string_fisheye_right.str(), fisheye_right_rec);
  cout << string_fisheye_right.str() << " was written" << endl;

  cout << "\n " << endl;
  i++;
}

int main(int argc, char **argv)
{
  // initialize ROS and specify the name of the node.
  ros::init(argc, argv, "fisheye_node");

  // create a handle to this node.
  ros::NodeHandle nh;

  // this class acts as a highest-level filter, simply passing messages from a ROS subscription through to the filters which have connected to it.
  message_filters::Subscriber<Image> fisheye_left_sub(nh, "/sensors/camera/fisheye_left/image_raw", 1);
  message_filters::Subscriber<Image> fisheye_middle_sub(nh, "/sensors/camera/fisheye_middle/image_raw", 1);
  message_filters::Subscriber<Image> fisheye_right_sub(nh, "/sensors/camera/fisheye_right/image_raw", 1);

  // the message_filters::sync_policies::ApproximateTime policy uses an adaptive algorithm to match messages based on their timestamp.
  typedef sync_policies::ApproximateTime<Image, Image, Image> MySyncPolicy;

  // ApproximateTime takes a queue size as its constructor argument, the name of each subscriber should also be provided.
  Synchronizer<MySyncPolicy> sync(MySyncPolicy(10), fisheye_left_sub, fisheye_middle_sub, fisheye_right_sub);

  // register multiple callbacks with the registerCallbacks() method, they will get called in the order they are registered.
  sync.registerCallback(boost::bind(&callback, _1, _2, _3));

  // all callbacks will be called from within the ros::spin() call, ros::spin() will not return until the node has been shutdown.
  ros::spin();

  return 0;
}
