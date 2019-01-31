
import Dataset
import Perceptron
import CrossValScore
from sklearn import datasets
import numpy as np
import matplotlib.pyplot as plt
import time
import pandas as pd
iris = datasets.load_iris()

dt = Dataset.Dataset()
dt.dados = iris.data
dt.classes = iris.target
dt.size_dados = len(dt.dados)
dt.size_features = len(dt.dados[0])
# dt.normalize()
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

model = Perceptron.Perceptron(epochs=1000, threshold=-1, activation='sig')

model.train(dt)
result = model.predict(dt_test)
print(result*100, "%")
