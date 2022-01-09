#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

/**
 * This script are used to load camera calibration data from yaml file.
 */

vector<Mat> load_data(const std::string &yaml_path)
{
	cv::Mat K, D;
	vector<Mat> calibration_data;

	cv::FileStorage opencv_file(yaml_path, cv::FileStorage::READ);
	opencv_file["camera_matrix"] >> K;
	opencv_file["distortion_coefficients"] >> D;
	opencv_file.release();

	calibration_data.push_back(K);
	calibration_data.push_back(D);

	return calibration_data;
}
