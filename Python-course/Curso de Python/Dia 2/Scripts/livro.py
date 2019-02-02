#!/usr/bin/python3
#coding:utf-8


class Livro(object):
	def __init__(self, nome, conteudo):
		self.nome = nome
		self.conteudo = conteudo

class LivroHTMLMixin(object):
	def renderizar(self):
		return ('<html><title>%s</title><body>%s</body></html>') % (self.nome, self.conteudo)

# A classe mixin apenas manipula os atributos

# Apenas a mixin sozinha não faz nada, ela depende da classe Livro
# mas ela não vai herdar a mesma.

# Apenas o objeto final vai ter os atributos,
# com o alto acoplamento entre as classes, faz sentido que ela exista.

#Uma classe mixin nao implementa o método __init__
#Sua função é agregar métodos à atributos de dados de outras classes.

class LivroHTML(Livro, LivroHTMLMixin):
	pass


livro_html = LivroHTML("Algum livro", "blablabla")
print(livro_html.renderizar())