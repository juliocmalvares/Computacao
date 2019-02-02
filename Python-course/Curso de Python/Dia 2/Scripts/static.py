
class Data:
	def __init__(self, dia, mes, ano):
		self.dia = dia
		self.mes = mes
		self.ano = ano

	"""
	pode ser herdado e sobrescrito
	"""

	@classmethod
	def de_string(cls, data_string):
		dia, mes, ano = map(int, data_string.split('-'))	
		data = cls(dia,mes,ano)
		return data
	"""
	O que o método acima faz ??
	Ele pega uma string em formato de data, no formato xx-xx-xxxx,
	quebra a string, cria um objeto, atribui à ele e retorna o objeto.
	

	cls é o "self" da classe.
	o cls referencia à classe, o self ao objeto
	"""

	def __str__(self):
		return '{}/{}/{}'.format(self.dia, self.mes, self.ano)

	
	"""
		o método static em python não referencia nada, basicamente.
		Não tem referencia ao objeto nem à classe.
		Ele é apenas uma função dentro de uma classe que faz alguma coisa
	"""
	@staticmethod
	def is_date_valid(data_string):
		dia, mes, ano = map(int, data_string.split('-'))
		return dia <= 31 and mes <= 12 and ano <= 9999


data = Data(10,10,2010)

data1 = Data.de_string('05-06-2018')

print(data)
print(data1)

print(Data.is_date_valid('05-06-2018'))
