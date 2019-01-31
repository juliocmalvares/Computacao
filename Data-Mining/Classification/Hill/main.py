#!/usr/bin/python3
#-*-encoding:utf8-*-

import time
import Dataset
import Perceptron
import CrossValScore

if __name__ == '__main__':
    dt = Dataset.Dataset('hill.csv')
    
    model = Perceptron.Perceptron(epochs=10, activation='sig', verbose=True)
    accuracy = CrossValScore.cross_val_score(model, dt, 10)
    print("Accuracy for 10 folds: ", accuracy.mean()*100)
    


