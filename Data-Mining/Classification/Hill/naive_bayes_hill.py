#from sklearn import svm

import sklearn.naive_bayes
import numpy as np
import matplotlib.pyplot as plt
import time
import Dataset
from sklearn.model_selection import cross_val_score
import seaborn as sns


sns.set()

dt = Dataset.Dataset('hill.csv')
inicio = time.time()
model = sklearn.naive_bayes.MultinomialNB()
resultados = cross_val_score(model, dt.dados, dt.classes, cv=10)


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
    valores.append(cross_val_score(model, dt.dados, dt.classes, cv=10).mean()*100)
    i+=.1

#print(valores)
valores_aux = np.array(valores)
print("Indice:", valores.index(valores_aux.max()), "Valor:", valores[valores.index(valores_aux.max())])

plt.plot(valores, label="Variação do alpha")
plt.ylim(80, 100)
plt.xlim(0, len(valores))
plt.ylabel("Porcentagem de acertos (%)")
plt.xlabel("Alpha * 10")
plt.legend()
plt.savefig("variacao_alpha_nb_hill.png")
plt.show()


# 0.01489 segundos
