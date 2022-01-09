#ifndef LOAD_DATA_H_
#define LOAD_DATA_H_
#include <opencv2/core/core.hpp>
using namespace std;
using namespace cv;
vector<Mat> load_data(const std::string &yaml_path);
#endif
