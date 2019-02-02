#!/usr/bin/python3
#coding: utf-8

from abc import ABCMeta, abstractmethod

class MinhaClasseAbstrata(metaclass=ABCMeta):

	@abstractmethod
	def action(self):
		pass

	@abstractmethod
	def action_2(self, o_que_fazer):
		pass

"""
Característica da classe abstrata: 
1 - Ela não pode ser diretamente instanciada
2 - Concebida para outras classes que devem implementar os métodos da classe
"""

#Exemplo real
class Animal(metaclass=ABCMeta):

	"""
	@abstractmethod
	def dizer_algo(self):
		pass
	"""
	@abstractmethod
	def dizer_algo(self):
		return 'Eu sou um animal'
	
	"""
	por convenção, não implementamos nada no método na classe abstrata,
	 a responsabilidade da implementação fica para as classes filhas,
	 mas por flexibilidade, as classes abstratas podem implementar algo 
	 em seus métodos abstratos.

	 Ex.: caso você tenha alguma feature que sempre ocorra, independente
	 do tipo da classe que herda, ela pode ser implementada apenas uma vez
	 na classe abstrata e herdada pelas filhas.
	"""
class Cachorro(Animal):
	def dizer_algo(self):
		s = super(Cachorro, self).dizer_algo()
		return '{} - {}'.format(s, 'AU AU')

	#se um dos métodos da classe abstrata não for instanciada,
	#quando o objeto for instanciado será levantado uma exception
	#dizendo que a classe filha deve implementar os métodos.

	def latir(self): #só para exemplificar que atributos a mais não interferem na metaclasse
		return 'AUAUAU'

c = Cachorro()
print(c.dizer_algo())
print(c.latir())
