#!/usr/bin/python3
#coding:utf-8

import numpy as np
import imageio

class LocalBinaryPattern(object):
    def __init__(self, image):
        self.image = imageio.imread(image)
        self.histogram = np.zeros(256)
        self.image_result = imageio.imread(image)
        self.padding = 1
    def apply(self):
        for i in range(len(self.image)):
            for j in range(len(self.image[0])):
                if i + self.padding < len(self.image) and j + self.padding < len(self.image[0]):
                    pass
                