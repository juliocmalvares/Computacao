#!/usr/bin/python3
#coding:utf-8

class Funcionario(object):
	def __init__(self, nome, salario, cpf):
		self.nome = nome
		self.salario = salario
		self.cpf = cpf
	
	def get_bonificacao(self):
		return self.salario * 0.10

class Gerente(Funcionario):

	#@Override
	def __init__(self, nome, salario, cpf, senha):
		super().__init__(nome,salario,cpf)
		self.senha = senha
	"""
		o comando super() referencia à classe pai, sempre.
		da mesma forma que o self referencia ao próprio objeto, o super referencia à
		classe pai
	"""

	#@Override
	def get_bonificacao(self):
		return super().get_bonificacao() + 1000.00


if __name__ == '__main__':
	g =  Gerente('Julio', 3000.00, '123123', 2)
	print("Nome: {}\nSalario: {}\nCPF: {}".format(g.nome, g.salario, g.cpf))
