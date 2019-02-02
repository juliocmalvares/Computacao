#!/usr/bin/python3
#coding: utf-8

import numpy as np
import matplotlib.pyplot as plt

dados = np.array([7,71, 319, 3487, 14401, 165939, 664471, 2193751, 7961951, 31436497])

plt.plot(dados, c='black', marker='o', ls='--', label='Quantidade')
plt.legend()
plt.ylabel('Soluções')
plt.xlabel('Coordenadas (por ID)')
#plt.axis('auto')
plt.grid(color='black', linestyle='--', linewidth=.1)
plt.savefig('graficosolucoes.png')
plt.show()