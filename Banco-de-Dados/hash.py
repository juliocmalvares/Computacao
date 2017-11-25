#!/usr/bin/python3
#-*-encoding:utf8-*-

#Júlio Césars Machado Álvares
#Liomar Caetano de Oliveira Junior
#Implementação de hashing extensível

class Pagina(object):
	def __init__(self):
		self.dados = list()
		self.indice = 0

		#a página contem uma lista de dados e um índice, sendo o índice o primeiro elemento dos dados

	def create_pagina(self, novos_dados):
		if novos_dados[0] is not '+' or novos_dados[0] is not '-':
			for i in range(len(novos_dados)):
				self.dados.append(novos_dados[i])
		self.config_pagina()

	#métodos para configurar e setar a página
	def config_pagina(self):
		for i in range(len(self.dados)):
			self.dados[i] = int(self.dados[i])
		self.indice = self.dados[0]



class Diretorio(object):
	global profundidade_global
	#configurações do diretório
	def __init__(self, qtd_paginas = 25):
		self.direc = list()
		self.profundidade_global = 2
		self.lista_buckets = list()
		self.quantidade_paginas = qtd_paginas
		self.start_direc()

	#iniciliazar o diretório
	def start_direc(self):
		for i in range(2**self.profundidade_global):
			self.direc.append(None)
			self.lista_buckets.append(Bucket(self.quantidade_paginas))
		self.set_bucket()

	#Função Hash
	def hash(self, index):
		return index % self.profundidade_global

	#Duplicar diretório
	def duplica_direc(self):
		for i in range(2**self.profundidade_global):
			self.direc.append(None)
		self.profundidade_global+=1
		self.set_bucket()

	#setar os bucket's
	def set_bucket(self):
		for i in range(len(self.direc)):
			for j in range(len(self.lista_buckets)):
				#indiceDir utilizado para aplicar função Hash e verificar qual diretório irá apontar para os novos bucket's
				indiceDir=i%self.profundidade_global
				#indiceBuc utilizado para definir qual a profundidade dos bucket's
				indiceBuc=j%self.lista_buckets[j].profundidade_local
				if self.profundidade_global > self.lista_buckets[j].profundidade_local:
					indiceDir = i % self.lista_buckets[j].profundidade_local
				if indiceDir == indiceBuc:
					self.direc[i] = self.lista_buckets[j]
	
	#buscar na lista itens com os mesmos índices			
	def busca_naLista(self, index):
		for i in range(len(self.lista_buckets)):
			if self.lista_buckets[i].index == index:
				return i
		return -1

	#destruir bucket's
	def destruct_bucket(self, index):
		bucket_aux = Bucket(self.quantidade_paginas, self.lista_buckets[index].profundidade_local)
		self.direc[index] = bucket_aux
		self.set_bucket()

	#inserir novo elemento
	def insere(self, pagina):
		index = self.hash(pagina.indice)
		#print("Ind:", pagina.indice, " Index", index, "PG", self.profundidade_global)
		#se é possível inserir, insere
		if self.direc[index].possivel_inserir():
			self.direc[index].insert_in_bucket(pagina)
			return
		#profundidade local do bucket é menor que a profundidade global; insere nova página e incrementa a profundidade local
		elif self.direc[index].profundidade_local < self.profundidade_global:
			addAux = list()
			self.direc[index].profundidade_local +=1
			self.lista_buckets.append(Bucket(self.quantidade_paginas, self.direc[index].profundidade_local))
			self.set_bucket()

			for i in range(len(self.direc[index].paginas)-1):
				addAux.append(self.direc[index].paginas[i])
				self.direc[index].paginas[i] = Pagina()
			for i in range(len(addAux)-1):
				self.insere(addAux[i])
			self.insere(pagina)
		#profundidade local igual a profundidade global; duplica diretório e insere novo bucket redistribuindo os elementos do bucket antigo
		elif self.direc[index].profundidade_local == self.profundidade_global:
			addAux = list()
			self.duplica_direc()
			self.direc[index].profundidade_local +=1
			self.lista_buckets.append(Bucket(self.quantidade_paginas, self.direc[index].profundidade_local))
			self.set_bucket()

			for i in range(len(self.direc[index].paginas)-1):
				addAux.append(self.direc[index].paginas[i])
				self.direc[index].paginas[i] = Pagina()
			for i in range(len(addAux)-1):
				self.insere(addAux[i])
			self.insere(pagina)

	#função para remover um elemento
	def remove(self, pagina):
		index = self.hash(pagina.indice)
		if self.direc[index].remove_in_bucket(index):
			print("Success")
		else:
			print("Fail")

	#função de pesquisar um elemento
	def search(self, index):
		indexAux = self.hash(index)
		return self.direc[indexAux].search_in_bucket(indexAux)

class Bucket(object):
	global qtd_pag
	def __init__(self, qtd_paginas = 25, profundidade = 2):
		self.paginas = list()
		self.vazio = []
		self.profundidade_local = profundidade
		self.start_bucket(qtd_paginas)
		self.qt_pag = qtd_paginas

	#verifica se é possível inserir
	def possivel_inserir(self):
		return len(self.vazio) > 0

	#inicializar os bucket's
	def start_bucket(self, qtd):
		for i in range(qtd):
			self.paginas.append(Pagina())
			self.vazio.append(i)

	#inserir no bucket
	def insert_in_bucket(self, nova_pagina):
		if len(self.vazio) > 0:
			self.paginas[self.vazio[0]] = nova_pagina
			self.vazio.pop(0)

	#pesquisar no bucket
	def search_in_bucket(self, index):
		for i in range(len(self.paginas)):
			if index == self.paginas[i].indice:
				return self.paginas[i]
		return None
		print("Erro, Indice nao encontrado")

	#procura a página com o elemento
	def search_index(self, index):
		for i in range(len(self.paginas)):
			if index == self.paginas[i].indice:
				return i
		return -1

	#remover página do bucket
	def remove_in_bucket(self, index):
		tmp = self.search_index(index)
		pag_aux = Pagina()
		if tmp is not -1:
			self.paginas[tmp] = pag_aux
			self.vazio.insert(0, tmp)
			return True
		else:
			print("Indice nao encontrado")
			return False


#funcao para executar as inserções e remoções do arquivo .csv gerado pelo siogen
def execute(direc):
	paginas = list()
	file = open('output.csv')
	add = list()
	remove = list()
	for linha in file:
		v = linha.split(',')
		if v[0] is '+':
			v.pop(0)
			paginas.append(Pagina())
			paginas[len(paginas)-1].create_pagina(v)
			add.append(paginas[len(paginas)-1])
		if v[0] is '-':
			v.pop(0)
			paginas.append(Pagina())
			paginas[len(paginas)-1].create_pagina(v)
			remove.append(paginas[len(paginas)-1])

	for i in range(len(add)):
		direc.insere(add[i])
	for i in range(len(remove)):
		direc.remove(remove[i])

if __name__ == '__main__':
	qt = int(input("Quantidade de páginas:"))

	direc = Diretorio(qtd_paginas = qt)

	while True:
		print("1 - Executar arquivo")
		print("2 - Inserir")
		print("3 - Remover")
		print("4 - Buscar")
		print("0 - Sair")
		op = int(input("Digite uma opcao: "))
		if op == 1:
			execute(direc)
		elif op == 2:
			pagina = Pagina()
			aux = list()
			for i in range(qt):
				aux[i] = input("Digite os dados: ")
			pagina.create_pagina(aux)
			direc.insere(aux)
		elif op == 3:
			pagina = Pagina()
			pagina.indice = int(input("Digite o indice: "))
			direc.remove(pagina)
		elif op == 4:
			aux = int(input("Digite o indice: "))
			pagina = direc.search(aux)
			print("Encontrado página com indice ", pagina.indice)
		elif op == 0:
			break
		else:
			break