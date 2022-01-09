#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/**
 * This script are used to correct fisheye camera according to calibration data from yaml file.
 */

cv::Mat fisheye_correction(Mat img, Mat K, Mat D)
{
	/**
	 * optional rectification transformation in the object space (3x3 matrix).
	 * If the matrix is empty, the identity transformation is assumed.
	 */
	cv::Mat R = cv::Mat::eye(3, 3, cv::DataType<double>::type);

	if (img.empty())
	{
		std::cout << "can not find img" << endl;
		return cv::Mat{};
	}

	/**
	 * mapx: x coordinates matrix of undistorted image.
	 * mapy: y coordinates matrix of undistorted image.
	 */
	Mat mapx, mapy, image_undistorted;

	/**
	 * compute the undistortion and rectification transformation map. 
	 */
	cv::fisheye::initUndistortRectifyMap(K, D, R, K, img.size(), CV_16SC2, mapx, mapy);

	/**
	 * apply a generic geometrical transformation to fisheye image 
	 * according to undistortion and rectification transformation map. 
	 */
	remap(img, image_undistorted, mapx, mapy, INTER_LINEAR, BORDER_CONSTANT);

	return image_undistorted;
}