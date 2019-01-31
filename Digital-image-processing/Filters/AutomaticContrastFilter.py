#!/usr/bin/python3

from skimage import io


class AutomaticContrastFilter(object):
    def __init__(self, img, scale_max, scale_min):
        self.name = img
        self.img = io.imread(img)
        self.scale_min = scale_min
        self.scale_max = scale_max

    def apply(self):
        red_hi = self.img[:, :, 0].max()
        red_low = self.img[:, :, 0].min()
        green_hi = self.img[:, :, 1].max()
        green_low = self.img[:, :, 1].min()
        blue_hi = self.img[:, :, 2].max()
        blue_low = self.img[:, :, 2].min()
        print(red_hi, red_low, green_hi, green_low, blue_hi, blue_low)
        for i in range(self.img.shape[0]):
            for j in range(self.img.shape[1]):
                #print((self.scale_min + (self.img[i, j, 0] - red_low)))
                #print((self.scale_max-self.scale_min)/(red_hi-red_low))
                red = int((self.scale_min + (self.img[i, j, 0] - red_low))*((self.scale_max-self.scale_min)/(red_hi-red_low)))
                green = int((self.scale_min + (self.img[i, j, 1] - green_low))*((self.scale_max-self.scale_min)/(green_hi-green_low)))
                blue = int((self.scale_min + (self.img[i, j, 2] - blue_low))*((self.scale_max-self.scale_min)/(blue_hi-blue_low)))

                #print('Old:', self.img[i,j,0],self.img[i,j,2],self.img[i,j,2])
                #print('New:', red, green, blue)
                #print('\n')
                self.img.itemset((i, j, 0), red)
                self.img.itemset((i, j, 1), green)
                self.img.itemset((i, j, 2), blue)

    def show(self):
        io.imshow(self.img)
        io.show()

    def img_save(self):
        io.imsave(self.name.split('.')[0] + '-contr.png', self.img)

    def return_img(self):
        return self.img


thr_filter = AutomaticContrastFilter('girassol.jpg', 255, 200)
thr_filter.apply()
thr_filter.show()
