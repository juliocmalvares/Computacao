#!/usr/bin/python3
# -*-encoding:utf8-*-

from sklearn import datasets
import time
import Dataset
import numpy as np
import CrossValScore
import Perceptron


threshold = -2
resultados = []
while threshold < 2:
    iris = datasets.load_iris()

    dt = Dataset.Dataset()
    dt.dados = iris.data
    dt.classes = iris.target
    dt.size_dados = len(dt.dados)
    dt.size_features = len(dt.dados[0])
    dt.normalize()



    model = Perceptron.Perceptron(epochs=50, threshold=threshold, activation='sig')

    test = [
    [5.0,  3.6, 1.4, 0.2], #0
    [5.4, 3.9, 1.7, 0.4], #0
    [4.6, 3.4, 1.4, 0.3], #0
    [5. , 3.4, 1.5, 0.2], #0
    [4.4, 2.9, 1.4, 0.2], #0
    [6.4, 3.2, 4.5, 1.5], #1
    [6.9, 3.1, 4.9, 1.5],#1
    [5.5, 2.3, 4.0, 1.3],#1
    [6.5, 2.8, 4.6, 1.5],#1
    [5.7, 2.8, 4.5, 1.3],#1
    [7.9, 3.8, 6.4, 2. ],#2
    [6.4, 2.8, 5.6, 2.2],#2
    [6.3, 2.8, 5.1, 1.5],#2
    [6.1, 2.6, 5.6, 1.4],#2
    [7.7, 3.0, 6.1, 2.3]#2
    ]

    test_saida = [0,0,0,0,0,1,1,1,1,1,2,2,2,2,2]

    dt_test = Dataset.Dataset()
    dt_test.dados = test
    dt_test.classes = test_saida
    dt_test.size_dados = len(dt_test.dados)
    dt_test.size_features = len(dt_test.dados[0])

    
    inicio = time.time()
    model.train(dt)
    value = model.predict(dt_test)*100
    fim = time.time()
    
    tempo = fim - inicio
    resultados.append((threshold, value, tempo))

    threshold += .1
    print(">> Feito: ", threshold)

with open('resultados_threshold_sig_iris.txt', 'w') as f:
    f.write("Testes de variação de threshold para a rede neural com a base de dados Hill.\nFormato (threshold, Accuracy, Tempo de execução)\n")
    for linha in resultados:
        f.write(str(linha)+'\n')