#!/usr/bin/python3
# -*-encoding:utf8-*-

import numpy as np
import time
import math
import Dataset

class Perceptron(object):
    def __init__(self, learn_rate=0.001, epochs=1000, threshold=-1, activation='relu', verbose=False):
        self.learn_rate = learn_rate
        self.epochs = epochs
        self.threshold = threshold
        self.weights = []
        self.activation = activation
        self.verbose = verbose

    def train(self, dados):
        aux = []
        for linha in dados.dados:
            aux.append(list(linha))
        for linha in aux:
            linha.insert(0, self.threshold)
        dados.dados = np.array(aux)
        self.weights = list(self.weights)
        for i in range(dados.size_features):
            self.weights.append(np.random.rand())
        self.weights.insert(0, self.threshold)
        self.weights = np.array(self.weights)

        n_epochs = 0
        while True:
            error = False
            for i in range(dados.size_dados):
                outNet = 0
                for k in range(dados.size_features):
                    outNet += float(self.weights[k] * dados.dados[i][k])
                
                if self.activation == 'relu':
                    outNet = self.relu(outNet)
                elif self.activation == 'tanh':
                    outNet = self.tanh(outNet)
                elif self.activation == 'deg':
                    outNet = self.deg(outNet)
                else:
                    outNet = self.sig(outNet)
                
                if outNet != dados.classes[i]:
                    cont_error = dados.classes[i] - outNet
                    for k in range(dados.size_features):
                        self.weights[k] += float(self.learn_rate * cont_error * dados.dados[i][k])
                    error = True
            n_epochs+=1
            if self.verbose:
                print(">>> Epoch:", n_epochs, "Error:", cont_error)
                # print(">>> Pesos:", self.weights)
                print(">>> Saida:", outNet)
            if not error or n_epochs > self.epochs:
                break
    
    def predict(self, test):
        outs = []
        outNet = 0
        for amostra in test.dados:
            for k in range(test.size_features):
                outNet += self.weights[k] * amostra[k]
            
            if self.activation == 'relu':
                outNet = self.relu(outNet)
            elif self.activation == 'tanh':
                outNet = self.tanh(outNet)
            elif self.activation == 'deg':
                outNet = self.deg(outNet)
            else:
                outNet = self.sig(outNet)
            outs.append(outNet)
        percent = 0
        for i in range(len(outs)):
            if outs[i] == test.classes[i]:
                percent+=1
        return percent/test.size_dados


    def relu(self, param):
        return np.max([0,param])
    
    def tanh(self, param):
        return np.tanh(param)
    
    def deg(self, param):
        return 1 if param >= 0 else 0
    
    def sig(self, param):
        value = 1 / (1 + np.exp(-param))
        return value
