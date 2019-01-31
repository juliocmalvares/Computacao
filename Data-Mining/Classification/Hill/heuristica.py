#!/usr/bin/python3
# -*-encoding:utf8-*-

import time
import Dataset
import Perceptron
import CrossValScore

acc = []
dt = Dataset.Dataset('hill.csv')

inicio = time.time()
model = Perceptron.Perceptron(epochs=268, threshold=-0.6, activation='deg')
accuracy = CrossValScore.cross_val_score(model, dt, 10).mean()*100
fim = time.time()
acc.append((accuracy, 'deg', fim-inicio))
print(fim-inicio)

incio = time.time()
model = Perceptron.Perceptron(epochs=224, threshold=-1.8, activation='sig')
accuracy = CrossValScore.cross_val_score(model, dt, 10).mean()*100
fim = time.time()
acc.append((accuracy, 'sig', fim-inicio))
print(fim-inicio)

inicio = time.time()
model = Perceptron.Perceptron(epochs=100, threshold=-2.0, activation='relu')
accuracy = CrossValScore.cross_val_score(model, dt, 10).mean()*100
fim = time.time()
acc.append((accuracy, 'relu', fim-inicio))
print(fim-inicio)

inicio = time.time()
model = Perceptron.Perceptron(epochs=100, threshold=-2.0, activation='tanh')
accuracy = CrossValScore.cross_val_score(model, dt, 10).mean()*100
fim = time.time()
acc.append((accuracy, 'tanh', fim-incio))
print(fim-inicio)

with open('ResultadosHeuristica.txt', 'w') as f:
    f.write("Resultados obtidos com a combinação dos melhores resultados: \n")
    for lin in acc:
        f.write(str(lin)+'\n')