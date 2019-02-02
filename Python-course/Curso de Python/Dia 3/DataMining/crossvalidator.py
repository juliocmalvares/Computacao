from sklearn import svm
from sklearn import datasets
from sklearn.model_selection import train_test_split
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import cross_val_score

iris = datasets.load_iris()
model = svm.SVC(kernel='linear', C=1)
resultados = cross_val_score(model, iris.data, iris.target, cv=10)

print("Resultados: ", resultados)
print('Accuracy: %0.3f +/- %0.3f' % (resultados.mean(), resultados.std()*2))