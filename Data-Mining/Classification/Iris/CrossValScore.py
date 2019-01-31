#!/usr/bin/python3
# -*-encoding:utf8-*-

import time
import Dataset
import numpy as np

def cross_val_score(model, dados, nfolds, dt_teste=None):
    accuracy = []
    if dt_teste == None:
        for i in range(nfolds):
            if type(dados) == type(Dataset.Dataset()):
                dados, test = dados.split_dados(1 - nfolds/100)
                model.train(dados)
                accuracy.append(model.predict(test))
                dados.join(test)
                print(">>> Done:", i)
            else:
                raise Exception("Invalid type of Data.")
        return np.array(accuracy)
    else:
        for i in range(nfolds):
            if type(dados) == type(Dataset.Dataset()):
                model.train(dados)
                accuracy.append(model.predict(dt_teste))
                print(">>> Done:", i)
            else:
                raise Exception("Invalid type of Data.")
        return np.array(accuracy)