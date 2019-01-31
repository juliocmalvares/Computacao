#!/usr/bin/python3
# -*-encoding:utf8-*-

import time
import Dataset
import numpy as np

def cross_val_score(model, dados, nfolds):
    accuracy = []
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