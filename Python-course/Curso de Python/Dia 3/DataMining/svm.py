#!/usr/bin/python3
#-*-encoding:utf8-*-

from sklearn import svm
from sklearn import datasets
from sklearn.model_selection import train_test_split
import numpy as np
import matplotlib.pyplot as plt


iris = datasets.load_iris()
x_train, x_test, y_train, y_test = train_test_split(iris.data, iris.target)
model = svm.SVC(kernel='linear', C=1).fit(x_train, y_train)
print(model.score(x_test, y_test)*100)
