#!/usr/bin/python3
#coding:utf-8

import sklearn.neighbors
from sklearn import datasets
from sklearn.model_selection import train_test_split
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import cross_val_score
import time
import seaborn as sns
sns.set()

iris = datasets.load_iris()
model = sklearn.neighbors.KNeighborsClassifier(n_neighbors=2)
resultados = cross_val_score(model, iris.data, iris.target, cv=10)

print("Resultados: ", resultados)
print('Accuracy: %0.3f +/- %0.3f' % (resultados.mean(), resultados.std()*2))

valores = []
for i in range(135):
    model = sklearn.neighbors.KNeighborsClassifier(n_neighbors=i+1)
    valores.append(cross_val_score(model, iris.data, iris.target, cv=10).mean()*100)

valores = np.array(valores)
aux = list(valores)
print("Index:", aux.index(valores.max()), "Valor:", valores.max())

inicio = time.time()
model = sklearn.neighbors.KNeighborsClassifier(n_neighbors=aux.index(valores.max()))
best_value = cross_val_score(model, iris.data, iris.target, cv=10)
fim = time.time()
print('Accuracy: %0.5f Execution: %.5f' % (best_value.mean(), fim-inicio))

plt.plot(valores, label="K-vizinhos")
plt.ylim(0, 100)
plt.xlim(0, len(valores))
plt.ylabel("Porcentagem de acertos (%)")
plt.xlabel("K")
plt.legend()
plt.savefig("kvizinhos_iris.png")
plt.show()
