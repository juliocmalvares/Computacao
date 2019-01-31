#!/usr/bin/python3
# -*-encoding:utf8-*-

import time
import Dataset
import Perceptron
import CrossValScore


resultados = []
for i in range(300):
    dt = Dataset.Dataset('hill.csv')
    model = Perceptron.Perceptron(epochs=i, activation='sig')
    
    # value = CrossValScore.cross_val_score(model, dt, 10).mean()*100
    dt, test = dt.split_dados(0.8)
    
    inicio = time.time()
    model.train(dt)
    value = model.predict(test)*100
    fim = time.time()
    
    tempo = fim - inicio
    resultados.append((i, value, tempo))
    print(">> Concluidos: ", i)

with open('resultados_epochs_sig.txt', 'w') as f:
    f.write("Testes de variação de epocas de treino para a rede neural com a base de dados Hill.\nFormato (Qt. epocas, Accuracy, Tempo de execução)\n")
    for linha in resultados:
        f.write(str(linha)+'\n')
