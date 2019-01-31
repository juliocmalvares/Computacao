#!/usr/bin/python3
# -*-encoding:utf8-*-

import numpy as np
import time
import math

class Dataset(object):
    def __init__(self, path_name="", delimiter=',', verbose = False):
        self.dados = None
        self.size_features = None
        self.size_dados = None
        self.classes = []
        self.delimiter = delimiter
        self.verbose = verbose

        line = ''
        aux = []
        if path_name != "":
            try:
                self.reader = open(path_name, 'r')
                for line in self.reader:
                    aux.append([float(p)
                                for p in line.split(self.delimiter)])

                for dado in aux:
                    self.classes.append(dado.pop(-1))
                self.dados = np.array(aux)
                self.size_features = len(self.dados[0])
                self.size_dados = len(self.dados)
                if self.verbose == True:
                    print("\t------ Data loaded successfully ------")
                    print("\t\t>> Samples size:", self.size_dados)
                    print("\t\t>> Features size:", self.size_features)
                    # print("\t\t>> Number of classes:", len(self.classes))
            except Exception:
                raise Exception("400: Error in loading data")
        else:
            return #implementar

    def normalize(self):
        maxi = 0
        mini = 0
        for i in range(self.size_features):
            maxi = self.dados[:,i].max()
            mini = self.dados[:,i].min()
            divisor = maxi - mini if maxi - mini != 0 else 1
            for k in range(self.size_dados):
                self.dados[k,i] = (self.dados[k,i] - mini)/divisor

    
    def split_dados(self, rate=0.8):
        train, test = Dataset(), Dataset()
        break_point = int(self.size_dados*rate)
        aux = []
        aux_classes = []
        for i in range(break_point):
            aux.append(self.dados[i])
            aux_classes.append(self.classes[i])
        train.dados = np.array(aux)
        train.classes = np.array(aux_classes)
        train.size_dados = len(train.dados)
        train.size_features = len(train.dados[0])

        aux.clear()
        aux_classes.clear()

        for i in range(self.size_dados - break_point):
            aux.append(self.dados[i+break_point])
            aux_classes.append(self.classes[i+break_point])
        
        test.dados = np.array(aux)
        test.classes = aux_classes
        test.size_dados = len(test.dados)
        test.size_features = len(test.dados[0])

        return train, test
    
    def join(self, other):
        if self.size_features == other.size_features:
            self.size_dados += other.size_dados
            self.dados = list(self.dados)
            self.classes = list(self.classes)
            for i in range(len(self.dados)):
                self.dados[i] = list(self.dados[i])
            for line in other.dados:
                self.dados.append(line)
            for clas in other.classes:
                self.classes.append(clas)

            self.dados = np.array(self.dados)
            self.classes = np.array(self.classes)        


# inicio = time.time()
# dt = Dataset('hill.csv')
# train, test = dt.split()
# fim = time.time()

# print(">> Train:", train.size_dados, train.size_features)
# print(">> Test:", test.size_dados, test.size_features)
