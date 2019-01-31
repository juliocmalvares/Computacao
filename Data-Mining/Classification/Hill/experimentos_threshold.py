#!/usr/bin/python3
# -*-encoding:utf8-*-

import time
import Dataset
import numpy as np
import CrossValScore
import Perceptron


threshold = -2
resultados = []
while threshold < 2:
    dt = Dataset.Dataset('hill.csv')
    model = Perceptron.Perceptron(epochs=50, threshold=threshold, activation='deg')

    dt, test = dt.split_dados(0.8)
    
    inicio = time.time()
    model.train(dt)
    value = model.predict(test)*100
    fim = time.time()
    
    tempo = fim - inicio
    resultados.append((threshold, value, tempo))

    threshold += .1
    print(">> Feito: ", threshold)

with open('resultados_threshold_deg.txt', 'w') as f:
    f.write("Testes de variação de threshold para a rede neural com a base de dados Hill.\nFormato (threshold, Accuracy, Tempo de execução)\n")
    for linha in resultados:
        f.write(str(linha)+'\n')