from skimage import io
import numpy as np
import math

class SobelEdgeDetector(object):
    def __init__(self, img):
        self.img = io.imread(img)
        self.name = img
        self.conv_gx = io.imread(img)
        self.conv_gy = io.imread(img)
        self.gx = np.array([[1, 0, -1], [2, 0, -2], [1, 0, -1]])
        self.gy = np.array([[1, 2, 1], [0, 0, 0], [-1, -2, -1]])
        self.img_result = io.imread(img)

    def __grayscaler(self):
        for i in range(self.img.shape[0]):
            for j in range(self.img.shape[1]):
                mean = int(
                    (int(self.img[i][j][0]) + int(self.img[i][j][1]) + int(self.img[i][j][2])) / 3)
                self.img.itemset((i, j, 0), mean)
                self.img.itemset((i, j, 1), mean)
                self.img.itemset((i, j, 2), mean)

    def __convolution(self):
        self.__grayscaler()
        for i in range(self.conv_gx.shape[0]):
            for j in range(self.conv_gx.shape[1]):
                self.conv_gx[i, j, 0] = 1
                self.conv_gx[i, j, 1] = 1
                self.conv_gx[i, j, 2] = 1
                self.conv_gy[i, j, 0] = 1
                self.conv_gy[i, j, 1] = 1
                self.conv_gy[i, j, 2] = 1
        centroit_gx = 0
        centroit_gy = 0
        pesogx = self.gx.sum()
        pesogy = self.gy.sum()
        for i in range(self.img.shape[0] - len(self.gx)):
            for j in range(self.img.shape[1] - len(self.gx)):
                for lin in range(len(self.gx)):
                    for col in range(len(self.gx)):
                        centroit_gx += int(self.img[lin+i,
                                                    col+j, 0] * self.gx[lin, col])
                        centroit_gy += int(self.img[lin+i,
                                                    col+j, 0] * self.gy[lin, col])
                if pesogx != 0:
                    centroit_gx += int(self.img[lin+i,
                                                col+j, 0] * self.gx[lin, col])
                if pesogy != 0:
                    centroit_gy += int(self.img[lin+i,
                                                col+j, 0] * self.gy[lin, col])
                
                if centroit_gx < 0:
                    centroit_gx = 1
                if centroit_gy < 0:
                    centroit_gy = 1
                
                if centroit_gx >= 255:
                    centroit_gx = 255
                if centroit_gy >= 255:
                    centroit_gy = 255
                self.conv_gx.itemset((i, j, 0), centroit_gx)
                self.conv_gx.itemset((i, j, 1), centroit_gx)
                self.conv_gx.itemset((i, j, 2), centroit_gx)
                self.conv_gy.itemset((i, j, 0), centroit_gy)
                self.conv_gy.itemset((i, j, 1), centroit_gy)
                self.conv_gy.itemset((i, j, 2), centroit_gy)
                centroit_gx = 0
                centroit_gy = 0
    
    def apply(self):
        self.__convolution()
        for i in range(self.img.shape[0]):
            for j in range(self.img.shape[1]):
                pix = int(math.sqrt((self.conv_gx[i][j][0]**2) + (self.conv_gy[i][j][0]**2)))
                if pix <= 0:
                    pix = 1
                elif pix >= 255:
                    pix = 255

                self.img_result.itemset((i,j,0), pix)
                self.img_result.itemset((i,j,1), pix)
                self.img_result.itemset((i,j,2), pix)


    def show(self):
        io.imshow(self.img_result)
        io.show()

    def img_save(self):
        io.imsave(self.name.split('.')[0] + '-edge.png', self.img_result)

    def return_img(self):
        return self.img_result


thr_filter = SobelEdgeDetector('cat2.jpg')
thr_filter.apply()
thr_filter.show()
