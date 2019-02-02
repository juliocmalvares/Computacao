#!/usr/bin/python3
#coding: utf-8
import matplotlib.pyplot as plt
import pandas as pd
import pydataset
import seaborn as sns

titanic = pydataset.data('titanic')

print(titanic.head())
print("Notemos que os dados não são numéricos !!\n\n")

print('Qts de cada classe: ', titanic['class'].value_counts())

titanic['class'].value_counts().plot(kind='bar')
plt.savefig('hist-01.png')
plt.show()

titanic['survived'].value_counts().plot(kind='bar')
plt.savefig('hist-02.png')
plt.show()


titanic.groupby('survived')['class'].value_counts().plot(kind='bar')
plt.savefig('hist-03.png')
plt.show()

titanic['class'].value_counts().hist()
plt.savefig('hist-04.png')
plt.show()