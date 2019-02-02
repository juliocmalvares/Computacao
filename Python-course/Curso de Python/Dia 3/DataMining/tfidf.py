#!/usr/bin/python3
#-*-encoding:utf8-*-

import sklearn.feature_extraction.text as sk
import numpy as np

def apply_inplace(lista):
    tf = sk.TfidfVectorizer()
    final = []
    for elem in lista:
        dados = np.array(tf.fit_transform(open(elem[1])).data)
        data = [dados, elem[-1]]
        final.append(data)
    return final
