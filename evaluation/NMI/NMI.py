import cv2
import numpy as np
import math

from MI import mutualInfo
from skimage.measure import shannon_entropy


def fusionFactor(img1, img2, fu_img):
    ff = mutualInfo(img1, fu_img)+mutualInfo(img2, fu_img)

    return ff


def fusionSymmetry(img1, img2, fu_img):
	MI1 = mutualInfo(img1, fu_img)
	MI2 = mutualInfo(img2, fu_img)

	fs = abs(MI1/(MI1+MI2) - 0.5)

	return fs


def QMI(img1, img2, fu_img):
    en1 = shannon_entropy(img1)
    en2 = shannon_entropy(img2)
    en_fu = shannon_entropy(fu_img)

    mi1 = mutualInfo(img1, fu_img)
    mi2 = mutualInfo(img2, fu_img)

    Qmi = 2.0*((mi1/(en1+en_fu))+(mi2/(en2+en_fu)))

    return Qmi


if __name__ == '__main__':
    img1 = cv2.imread('L2.jpg', 0)
    img2 = cv2.imread('R2.jpg', 0)
    img_fu = cv2.imread('NMI.jpg', 0)

    print(fusionFactor(img1, img2, img_fu))
    print(fusionSymmetry(img1, img2, img_fu))
    print(QMI(img1, img2, img_fu))
