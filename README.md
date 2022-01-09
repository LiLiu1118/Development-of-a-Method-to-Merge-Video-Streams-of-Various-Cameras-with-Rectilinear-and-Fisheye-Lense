# Table of contents
1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Supervisor](#supervisor)
4. [Member](#member)

## Introduction 
This ROS project is the workspace of Advanced Design Project "Development of a Method to Merge Video Streams of Various Cameras with Rectilinear and Fisheye Lenses". Only one package has been implemented so far, which realizes fisheye camera images synchronization and correction with OpenCV and the ROS framework. If you want to use the functions, you also need the calibration data of the camera.

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


