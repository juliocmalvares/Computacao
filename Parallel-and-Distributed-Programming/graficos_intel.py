#!/usr/bin/python3
#coding: utf-8

import numpy as np
import matplotlib.pyplot as plt


exec_seq = np.array([0.000157, 0.004498, 0.017263, 0.156577, 0.620496, 7.200473, 28.533579, 93.742440, 337.259533, 1258.483783])
exec_par = np.array([0.026332, 0.051649, 0.047676, 0.077664, 0.333466, 3.417465, 22.385052, 64.149772, 202.153245, 1105.591386])
exec_dist = np.array([0.011615, 0.021488, 0.015723, 0.103047, 0.475226, 5.046896, 17.478684, 63.736599, 219.063759, 2170.412446])


plt.plot(exec_seq, c='black', marker='o', ls='--', label='Sequencial')
plt.plot(exec_par, c='darkblue', marker='o', ls='--', label='Paralelo')
plt.plot(exec_dist, c='dodgerblue', marker='o', ls='--', label='Paralelo e Distribuído')
plt.legend()
plt.ylabel('Tempo de execução (s)')
plt.xlabel('Coordenadas (por ID)')
plt.axis('auto')
plt.grid(color='black', linestyle='--', linewidth=.1)
plt.savefig('graficointel.png')
plt.show()
