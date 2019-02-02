#!/usr/bin/python3
#coding: utf-8

import numpy as np
import matplotlib.pyplot as plt


exec_seq = np.array([0.000724, 0.003687, 0.014090, 0.131676, 0.522095, 6.119439, 25.397143, 78.296651, 284.788489, 1147.230041])
exec_par = np.array([0.002925, 0.009612, 0.027250, 0.194929, 0.756202, 8.537793, 34.130704, 117.288454, 417.413515, 1635.354696])
exec_dist = np.array([0.005511, 0.008967, 0.017188, 0.126708, 0.481820, 5.521914, 21.627552, 72.922474, 258.487852, 1019.447437])


plt.plot(exec_seq, c='black', marker='o', ls='--', label='Sequencial')
plt.plot(exec_par, c='darkblue', marker='o', ls='--', label='Paralelo')
plt.plot(exec_dist, c='dodgerblue', marker='o', ls='--', label='Paralelo e Distribuído')
plt.legend()
plt.ylabel('Tempo de execução (s)')
plt.xlabel('Coordenadas (por ID)')
plt.axis('auto')
plt.grid(color='black', linestyle='--', linewidth=.1)
plt.savefig('grafico_amd.png')
plt.show()
