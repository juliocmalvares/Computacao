#!/usr/bin/python3
#coding: utf-8

import matplotlib.pyplot as plt
import pandas as pd
import seaborn
import pydataset

def specie_color(x):
    if x == 'setosa':
        return 0
    elif x == 'versicolor':
        return 1
    return 2


seaborn.set_style('whitegrid')
df = pydataset.data('AirPassengers')

print('Dataset de passageiros: \n', df.head(10))

plt.plot(df['time'], df['AirPassengers'])
plt.show()
plt.savefig('serie-01.png')

plt.scatter(df['time'], df['AirPassengers'])
plt.show()
plt.savefig('disperc-01.png')

iris = pydataset.data('iris')
print('Dataset Iris: \n', iris.head(10))

plt.scatter(iris['Sepal.Length'], iris['Sepal.Width'], sizes=iris['Petal.Length'])
plt.show()

iris['SpeciesNumber'] = iris['Species'].apply(specie_color)

print(iris.head(10))

plt.scatter(
    iris['Sepal.Length'], iris['Sepal.Width'], sizes=5*iris['Petal.Length'],
    c=iris['SpeciesNumber'], cmap='viridis', alpha=0.4
)
plt.show()