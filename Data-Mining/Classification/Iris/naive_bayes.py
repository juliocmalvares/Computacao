#from sklearn import svm

import sklearn.naive_bayes
from sklearn import datasets
from sklearn.model_selection import train_test_split
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import cross_val_score
import time
import seaborn as sns
sns.set()

iris = datasets.load_iris()
inicio = time.time()
model = sklearn.naive_bayes.MultinomialNB()
resultados = cross_val_score(model, iris.data, iris.target, cv=10)


print("Resultados: ", resultados)
print('Accuracy: %0.3f +/- %0.3f' % (resultados.mean(), resultados.std()*2))
fim = time.time()

print("Tempo: ",fim-inicio)

valores = []
i = .1
aux = []
while i < 20:
    aux.append(i)
    model = sklearn.naive_bayes.MultinomialNB(alpha=i)
    valores.append(cross_val_score(model, iris.data, iris.target, cv=10).mean()*100)
    i+=.1

valores_aux = np.array(valores)
print("Indice:", valores.index(valores_aux.max()), "Valor:", valores[valores.index(valores_aux.max())])


plt.plot(valores, label="Variação do alpha")
plt.ylim(90, 100)
plt.xlim(0, len(valores))
plt.ylabel("Porcentagem de acertos (%)")
plt.xlabel("Alpha * 10")
plt.legend()
plt.savefig("variacao_alpha_nb.png")
plt.show()
