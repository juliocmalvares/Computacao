#!/usr/bin/python3
#coding:utf-8

class Operador():
	def __init__(self, num):
		self.num = num
	
	def __add__(self, op):
		return self.num - op.num
	
	def __mul__(self, op):
		return self.num ** op.num

	def __sub__(self, op):
		return self.num + op.num

if __name__ == '__main__':
	op = Operador(10)
	op2 = Operador(20)
	print("Soma sobrecarregada: ",op + op2)
	print("Mult sobrecarregada: ",op * op2)
	print("Sub sobrecarregada: ",op - op2)