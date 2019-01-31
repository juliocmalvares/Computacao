#!/usr/bin/python3
# -*-encoding:utf8-*-

import time
import Dataset
import Perceptron
from sklearn import datasets
import CrossValScore

acc = []
iris = datasets.load_iris()

dt = Dataset.Dataset()
dt.dados = iris.data
dt.classes = iris.target
dt.size_dados = len(dt.dados)
dt.size_features = len(dt.dados[0])
dt.normalize()


# value = CrossValScore.cross_val_score(model, dt, 10).mean()*100
test = [
    [5.0,  3.6, 1.4, 0.2],  # 0
    [5.4, 3.9, 1.7, 0.4],  # 0
    [4.6, 3.4, 1.4, 0.3],  # 0
    [5., 3.4, 1.5, 0.2],  # 0
    [4.4, 2.9, 1.4, 0.2],  # 0
    [6.4, 3.2, 4.5, 1.5],  # 1
    [6.9, 3.1, 4.9, 1.5],  # 1
    [5.5, 2.3, 4.0, 1.3],  # 1
    [6.5, 2.8, 4.6, 1.5],  # 1
    [5.7, 2.8, 4.5, 1.3],  # 1
    [7.9, 3.8, 6.4, 2.],  # 2
    [6.4, 2.8, 5.6, 2.2],  # 2
    [6.3, 2.8, 5.1, 1.5],  # 2
    [6.1, 2.6, 5.6, 1.4],  # 2
    [7.7, 3.0, 6.1, 2.3]  # 2
]
test_saida = [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2]
dt_test = Dataset.Dataset()
dt_test.dados = test
dt_test.classes = test_saida
dt_test.size_dados = len(dt_test.dados)
dt_test.size_features = len(dt_test.dados[0])


inicio = time.time()
model = Perceptron.Perceptron(epochs=3, threshold=-0.9, activation='deg')
accuracy = CrossValScore.cross_val_score(model, dt, 10,dt_test).mean()*100
fim = time.time()
acc.append((accuracy, 'deg', fim-inicio))
print(fim-inicio)

incio = time.time()
model = Perceptron.Perceptron(epochs=10, threshold=-1, activation='sig')
accuracy = CrossValScore.cross_val_score(model, dt, 10,dt_test).mean()*100
fim = time.time()
acc.append((accuracy, 'sig', fim-inicio))
print(fim-inicio)


inicio = time.time()
model = Perceptron.Perceptron(epochs=10, threshold=-1, activation='relu')
accuracy = CrossValScore.cross_val_score(model, dt, 10,dt_test).mean()*100
fim = time.time()
acc.append((accuracy, 'relu', fim-inicio))
print(fim-inicio)


inicio = time.time()
model = Perceptron.Perceptron(epochs=281, threshold=1.3, activation='tanh')
accuracy = CrossValScore.cross_val_score(model, dt, 10, dt_test).mean()*100
fim = time.time()
acc.append((accuracy, 'tanh', fim-incio))
print(fim-inicio)


with open('ResultadosHeuristicaIris.txt', 'w') as f:
    f.write("Resultados obtidos com a combinação dos melhores resultados: \n")
    for lin in acc:
        f.write(str(lin)+'\n')