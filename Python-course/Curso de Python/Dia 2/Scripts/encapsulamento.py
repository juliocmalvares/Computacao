#!/usr/bin/python3
#coding:utf-8

class P():

	def __init__(self, x):
		self.x = x

	#foi criada uma nova propriedade sobre o atributo x
	@property
	def x(self):  #metodo get
		return self._x
	#esse método será invocado quando alguem tentar
	#invocar o atributo x dessa classe

	@x.setter
	def x(self, x):
		if x > 0: #encapsulamento só faz sentido seguindo uma regra
			self._x = x
	#esse método será invocado quando alguem tentar 
	#modificar o atributo x dessa classe


if __name__ == '__main__':		
	p = P(10)
	print(p.x)
	p.x = -1
	print(p.x)


"""
Notem que o acesso a variável é dado de forma direta e explícita,
gerando assim maior legibilidade e facilidade.
O encapsulamento de código em python condiz com as regras que serão
submetidas aos seus atributos de classes e não diretamente
com o acesso das variáveis, como é feito em Java, por exemplo.
"""