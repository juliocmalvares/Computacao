#!/usr/bin/python3
# -*-encoding:utf8-*-

import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
sns.set()
# sns.set_style('whitegrid')

dados_relu = []
dados_sig = []
dados_tanh = []
dados_deg = []


f = open('resultados_epochs_relu.txt', 'r')
f.readline()
f.readline()
for line in f:
    dados_relu.append(float(line.split(',')[1]))
f.close()

f = open('resultados_epochs_sig.txt', 'r')
f.readline()
f.readline()
for line in f:
    dados_sig.append(float(line.split(',')[1]))
f.close()


f = open('resultados_epochs_tanh.txt', 'r')
f.readline()
f.readline()
for line in f:
    dados_tanh.append(float(line.split(',')[1]))
f.close()

f = open('resultados_epochs_deg.txt', 'r')
f.readline()
f.readline()
for line in f:
    dados_deg.append(float(line.split(',')[1]))
f.close()

plt.plot(dados_relu, label='ReLU')
plt.plot(dados_sig, label='Sigmoide')
plt.plot(dados_deg, label='Degrau')
plt.plot(dados_tanh, label='Tanh')

plt.xlim(0, len(dados_relu))
plt.ylim(0,100)
plt.ylabel("Porcentagem (%)")
plt.xlabel("Variação de épocas")
plt.legend()
plt.savefig("activation_epochs.png")

plt.show()

dados_relut = []
dados_sigt = []
dados_tanht = []
dados_degt = []

y = []
i = -2
while i < 2:
    y.append(i)
    i+=.1

f = open('resultados_threshold_sig.txt', 'r')
f.readline()
f.readline()
for line in f:
    dados_sigt.append(float(line.split(',')[1]))
f.close()


f = open('resultados_threshold_tanh.txt', 'r')
f.readline()
f.readline()
for line in f:
    dados_tanht.append(float(line.split(',')[1]))
f.close()


f = open('resultados_threshold_deg.txt', 'r')
f.readline()
f.readline()
for line in f:
    dados_degt.append(float(line.split(',')[1]))
f.close()


f = open('resultados_threshold_relu.txt', 'r')
f.readline()
f.readline()
for line in f:
    dados_relut.append(float(line.split(',')[1]))
f.close()

plt.plot(dados_relut, label='ReLU')
plt.plot(dados_sigt, label='Sigmoide')
plt.plot(dados_degt, label='Degrau')
plt.plot(dados_tanht, label='Tanh')

plt.xlim(0, 40)
plt.ylim(0,100)
plt.ylabel("Porcentagem (%)")
plt.xlabel("Variação de threshold")
plt.legend()
plt.savefig("activation_thresold.png")

plt.show()



deg_ep = []
relu_ep = []
sig_ep = []
tanh_ep = []
i = 0
while i < len(dados_deg):
    deg_ep.append((i, dados_deg[i]))
    sig_ep.append((i, dados_sig[i]))
    relu_ep.append((i, dados_relu[i]))
    tanh_ep.append((i, dados_tanh[i]))
    i+=1

i = 0
deg_th = []
relu_th = []
sig_th = []
tanh_th = []
while i < len(dados_degt):
    deg_th.append((i, dados_degt[i]))
    sig_th.append((i, dados_sigt[i]))
    relu_th.append((i, dados_relut[i]))
    tanh_th.append((i, dados_tanht[i]))
    i+=1




deg_ep.sort(key=lambda x:x[-1], reverse=True)
sig_ep.sort(key=lambda x:x[-1], reverse=True)
relu_ep.sort(key=lambda x:x[-1], reverse=True)
tanh_ep.sort(key=lambda x:x[-1], reverse=True)

deg_th.sort(key=lambda x:x[-1], reverse=True)
sig_th.sort(key=lambda x:x[-1], reverse=True)
relu_th.sort(key=lambda x:x[-1], reverse=True)
tanh_th.sort(key=lambda x:x[-1], reverse=True)


print("Melhor época Deg:", deg_ep[0])
print("Melhor época Sig:", sig_ep[0])
print("Melhor época Tanh:", tanh_ep[0])
print("Melhor época ReLU:", relu_ep[0])

print("Melhor thresold Deg:", deg_th[0])
print("Melhor thresold Sig:", sig_th[0])
print("Melhor thresold Tanh:", tanh_th[0])
print("Melhor thresold ReLU:", relu_th[0])


#Melhor epoca deg 268 th 14*0.1+-2 = -0.6
#melhor epoca sig 224 th 2*.1+-2 = -1.8

