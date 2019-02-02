#!/usr/bin/python3
#coding: utf-8
import nltk
import os
import tfidf
import matplotlib.pyplot as plt

stopwords = nltk.corpus.stopwords.words('english')

def tokens(text):
	return text.split()

def list_arq(path, state):
	final = list()
	curr = os.getcwd()
	os.chdir(path)
	arquivos = [os.getcwd() + '/' + p for p in os.listdir()]
	os.chdir(curr)
	for arq in arquivos:
		final.append([arq, state])
	return final

def remove_words(texto):
	palavras = tokens(texto[0])
	texto[0] = [p for p in palavras if p not in stopwords]
	texto[0] = stringer(texto[0])
	return texto

def apply_stemmer(texto):
	stemmer = nltk.stem.SnowballStemmer('english')
	palavras = tokens(texto[0])
	texto[0] = [str(stemmer.stem(p)) for p in palavras]
	texto[0] = stringer(texto[0])
	return texto

def escritor(lista):
	contp, contn = 0, 0
	final = []
	for elem in lista:
		if elem[-1] == 1:
			dado = [elem[0], os.getcwd()+'/Dados/pos'+str(contp)+'.txt', elem[1]]
			contp+=1
			with open(dado[1], 'w') as fl:
				fl.write(dado[0])
			final.append(dado)
		elif elem[-1] == -1:
			dado = [elem[0], os.getcwd()+'/Dados/neg'+str(contn)+'.txt', elem[1]]
			contn+=1
			with open(dado[1], 'w') as fl:
				fl.write(dado[0])
			final.append(dado)
	return final

def generate_scatter(dados):
	plt.scatter(dados[0], range(len(dados[0])))
	plt.savefig('disperc.png')
	plt.show()

def stringer(lista):
	texto = ''
	for palavras in lista:
		texto += palavras + ' '
	return texto

if __name__ == '__main__':
	arquivos = list_arq('neg', -1)
	arquivos += list_arq('pos', 1)

	lista = []
	for elem in arquivos:
		lista.append([open(elem[0]).read(), elem[1]])

	lista = list(map(remove_words, lista))
	lista = list(map(apply_stemmer, lista))
	lista = escritor(lista)
	dados = tfidf.apply_inplace(lista)
	generate_scatter(dados[3])