# Table of contents
1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Supervisor](#supervisor)
4. [Member](#member)

## Introduction 
As a part of the MAAS project, this ADP mainly researches on the  methods to stitch video streams of various cameras with rectilinear and fisheye lenses. The focus is to present the video data from the cameras of the tram to the operator in such a way, that the operator can easily understand the tram’s environment and the tram's current state. With the stitched video stream, the operator can get an immersive operating experience, thereby improving the safety of teleoperation.

We have investigated and compared different fisheye camera correction and image stitching methods. Besides, we used the fisheye images as well as the images taken by ourselves to verify the effectiveness of different algorithms. Although the image stitching results are not ideal, we explored the origin behind it. In the implementation procedure, we have a deep understanding of the applicable conditions of homography and the influencing factors that affect the feature points detection and matching process. After extensively reading the relevant literature and debugging different algorithms, we have a broad understanding of commonly used image stitching methods and their respective theories. In addition, we implemented image synchronization and rectification with the help of OpenCV under the ROS framework. The architecture of ROS makes it more convenient to deploy this function on different platforms.


## Usage 
Firstly you need to create a ROS workspace, please refer to [ROS Tutorials](http://wiki.ros.org/ROS/Tutorials).

Calibration data of the cameras need to be placed in [camera_calibration](camera_calibration). \
Our Calibration: [left](camera_calibration/fisheye_left.yaml), [middle](camera_calibration/fisheye_middle.yaml), [right](camera_calibration/fisheye_right.yaml) \
ROS Calibration: [left](camera_calibration/fisheye_ROS_left.yaml), [middle](camera_calibration/fisheye_ROS_middle.yaml), [right](camera_calibration/fisheye_ROS_right.yaml) \
OpenCV Calibration: [left](camera_calibration/fisheye_OpenCV_left.yaml), [middle](camera_calibration/fisheye_OpenCV_middle.yaml), [right](camera_calibration/fisheye_OpenCV_right.yaml)

Source code are placed in [src/fisheye_synchronization_correction/src](src/fisheye_synchronization_correction/src). Header files are located in [src/fisheye_synchronization_correction/include/fisheye_synchronization_correction](src/fisheye_synchronization_correction/include/fisheye_synchronization_correction).

CMakeLists.txt of fisheye synchronization and correction package is located in [src/fisheye_synchronization_correction](src/fisheye_synchronization_correction).

If you want to add new dependencies yourself, you can modify this file.

[build](build) is the default location of the build space and is where cmake and make are called to configure and build your packages.

[devel](devel) the default location of the devel space, which is where your executables and libraries go before you install your packages. 

[evaluation](evaluation) contains scripts for calculating different metrics: [NMI](evaluation/NMI), [PSNR](evaluation/PSNR), [SF](evaluation/SF), [SSIM](evaluation/SSIM), [STD](evaluation/STD), [VIFF](evaluation/VIFF)

## Supervisor 
Patrick Pintscher, M.Sc.\
Cheng Wang, M.Sc.

## Member 
Li Liu\
Cheng-Ting Tsai\
Chenhao Tang\
Qiong Ge\
Peng Yan\
Tobias Drebert\
Cedric Derstroff


