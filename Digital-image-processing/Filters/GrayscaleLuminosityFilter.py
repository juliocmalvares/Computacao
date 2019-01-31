#!/usr/bin/python3
#coding: utf-8

from skimage import io

class GrayscaleLuminosityFilter(object):
	def __init__(self, img):
		self.name = img
		self.img = io.imread(img)

	def apply(self):
		for i in range(self.img.shape[0]):
			for j in range(self.img.shape[1]):
				self.img.itemset((i,j,0), float(self.img[i][j][0]*0.21))
				self.img.itemset((i,j,1), float(self.img[i][j][1]*0.72))
				self.img.itemset((i,j,2), float(self.img[i][j][2]*0.07))

	def show(self):
		io.imshow(self.img)
		io.show()
	
	def img_save(self):
		io.imsave(self.name.split('.')[0] + '-grayscalelum.png', self.img)

g_filter = GrayscaleLuminosityFilter('Lais.jpeg')
g_filter.apply()
g_filter.show()
g_filter.img_save()
