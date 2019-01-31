#from sklearn import svm

import sklearn.neighbors
from sklearn import datasets
from sklearn.model_selection import train_test_split
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import cross_val_score
import time
import Dataset
import seaborn as sns
sns.set()

dt = Dataset.Dataset('hill.csv')
model = sklearn.neighbors.KNeighborsClassifier(n_neighbors=2)
resultados = cross_val_score(model, dt.dados, dt.classes, cv=10)


print(resultados.mean())

valores = []
for i in range(500):
    if i != 0 and i < dt.size_dados:
        model = sklearn.neighbors.KNeighborsClassifier(n_neighbors=i)
        valores.append(cross_val_score(model, dt.dados, dt.classes, cv=10).mean()*100)
valores = np.array(valores)

aux = list(valores)
print("Index:", aux.index(valores.max()), "Valor:", valores.max())

inicio = time.time()
model = sklearn.neighbors.KNeighborsClassifier(n_neighbors=33)
best_value = cross_val_score(model, dt.dados, dt.classes, cv=10)
fim = time.time()
print('Accuracy: %0.5f Execution: %.5f' % (best_value.mean(), fim-inicio))

plt.plot(valores, label="K-vizinhos")
plt.ylim(40, 80)
plt.xlim(0, len(valores))
plt.ylabel("Porcentagem de acertos (%)")
plt.xlabel("K")
plt.legend()
plt.savefig("kvizinhos_hill.png")
plt.show()

#best value = 64% com 1 vizinho 0.0610 segundos
