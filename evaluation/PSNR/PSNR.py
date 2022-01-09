import cv2
import numpy as np
import math

import skimage.measure


def psnr1(img1, img2):
   mse = np.mean((img1/1.0 - img2/1.0) ** 2)
   if mse < 1.0e-10:
      return 100
   return 10 * math.log10(255.0**2/mse)


def psnr2(img1, img2):
   mse = np.mean((img1/255. - img2/255.) ** 2)
   if mse < 1.0e-10:
      return 100
   PIXEL_MAX = 1
   return 20 * math.log10(PIXEL_MAX / math.sqrt(mse))


if __name__ == '__main__':
   image = cv2.imread('1.jpeg', 0)
   img_fu = cv2.imread('flu.jpeg', 0)
   print(psnr1(image, img_fu))
   print(psnr2(image, img_fu))
   print(skimage.measure.compare_psnr(image, img_fu, data_range=255))
