import cv2
import numpy as np

image = cv2.imread('Group a.jpg', 0)

(mean, stddv) = cv2.meanStdDev(image)

print(mean)

print(stddv)
