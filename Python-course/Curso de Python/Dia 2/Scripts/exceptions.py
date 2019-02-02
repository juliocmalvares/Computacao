#!/usr/bin/python3
#coding: utf-8

class SomentePares(list):

	def append(self, inteiro):
		if not isinstance(inteiro, int):
			raise TypeError('Somente inteiros podem ser adicionados')
		if inteiro % 2:
			raise ValueError('Somente pares podem ser adicionados')

		super().append(inteiro)

"""
A classe somentepares herda da classe list.
o metodo append foi sobrescrito para ter um comportamento como eu definir.
No caso, desejo apenas que numeros inteiros e pares sejam adicionados a minha
"lista"

A palavra reservada raise lança exceções
"""

sp = SomentePares()
sp.append(10)
sp.append(20)
sp.append(4)


def f():
	raise Exception('exception')

try:
	f()
except Exception: #captura qualquer exceção que aparecer
	print('Foi disparado uma exception')



def divisao(divisor):
	try:
		return 10/divisor
	except ZeroDivisionError:
		return 'Divisão por 0 nao rola!'
	except TypeError:
		return 'Entre com um valor numérico'

print(divisao('10'))