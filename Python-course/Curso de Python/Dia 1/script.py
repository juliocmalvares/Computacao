#!/usr/bin/python3
#-*-coding:utf8-*-

#para compilar esse script, digite no terminal: "python3 script.py"

print("Usando o ponto e vírgula");print("Usando o ponto e vírgula 2")

#comentario simples
"""
comentario em varias linhas !!
"""

nome_pessoa = 'Julio'
idade = 21
altura = 1.92 #separa-se a parte inteira da fracionária com ponto
######################################################################################
print("\n\n----Utilização da função type()----")
print(type(nome_pessoa))
print(type(idade))
print(type(altura))

print("Conversão de tipos: ")
print(str(idade))
print(type(str(idade)))

print("Multiplicando strings !!" * 10)

print("\n\n----Utilizando a função input()----")
nome = str(input("Digite o nome da pessoa: "))
idade = int(input("Digite a idade da pessoa: "))

print(nome, type(nome))
print(idade, type(idade))

######################################################################################
print("\n\n----Operações Matemáticas----")
print("5/2: ", 5/2, type(5/2))
print("3+2: ", 3+2, type(3+2))
######################################################################################
print("\n\n----Operações Lógicas----")
print("True and True: ", True and True, type(True and True))
print("True and False: ", True and False, type(True and False))
print("True or True: ", True or True, type(True or True))
print("True and False: ", True or False, type(True or False))

######################################################################################
print("\n\n----Listas----")
lista = list() #pode ser definida com a função list
lista2 = [] #ou com colchetes

lista2 = [1,2,3,4,5]
lista = ['um', 'dois', 'três']

for elem in lista:
    print(elem)
for elem in lista2:
    print(elem)

lista.append(6)
lista.append(7)
print(lista)

lista2.append('quatro')
lista2.append('cinco')
print(lista2)

print("\nElemento 0: ", lista.pop(0)) #pop retorna o elemento
print("\nLista: ", lista)
print("\nElemento 0: ", lista2.pop(0))
print("\nLista2: ", lista2)
lista_total = lista + lista2
print("\nLista_total: ", lista_total) #listas podem ter objetos heterogêneos

######################################################################################
print("\n\n----Tuplas----")
tp = ()
tp2 = tuple()

tp = (1,2,3)
tp2 = ('um', 'dois', 'três')

for elem in tp:
    print(elem)
for elem in tp2:
    print(elem)


######################################################################################
print("\n\n----Uso do While e For----")

cont = 0
while True:
    cont+=1
    if cont == 20:
        break
    else:
        continue
print("Cont while: ", cont)
cont = 0
for elem in range(10):
    cont +=1
print("Cont for: ",cont)


######################################################################################
print("\n\n----List Comprehensions----")

lista = [p for p in range(10)]
print("Lista: ", lista)

square = [p*p for p in lista]
print("Square: ", square)

square_5 = [p*p for p in lista if p < 5]
print("Square < 5: ", square_5)

######################################################################################
print("\n\n----Atribuição condicional----")
print("Não consta nos slides !!")

"""
Atribuição condicional em python é o operador ternários das outras linguagens
extremamente útil
"""

a = 5
b = a if a <= 5 else 10
print(b)
a = 6
b = a if a <= 5 else 10
print(b)

"""
Como seria normalmente: 

if a <= 5:
    b = 5
else:
    b = 10
"""

######################################################################################
print("\n\n----Strings----")

text = "Senhor dos anéis é melhor que Harry Potter"
#percorrendo
for letra in text:
    print(letra)

#split
lista = text.split(" ")
print(lista)

#replace
text = text.replace('melhor', 'muito melhor')
print(text)

######################################################################################

print("\n\n----Funções e Procedimentos")

def soma(x1, x2):
    return x1+x2

def soma_mul(x1,x2):
    return x1+x2, x1, x2

def dados(nome = 'Julio', idade = 21):
    print("Nome: {} \nIdade: {}".format(nome, idade))

def lista_args(*args):
    print(args)

def dic_args(**args):
    print(args)


print("Soma 2, 3: ", soma(2,3))
print("Soma com retorno multiplo: ", soma_mul(2,3))
print("Dados sem argumentos: ")
dados()
print("Dados com argumentos: ")
dados(nome="Maria", idade=23)
print("Func variádica, Lista args: ")
lista_args(1,2,3,4,5)
print("Func variádica, Lista args: ")
dic_args(x1=1,x2=2,x3=3,x4=4,x5=5)

######################################################################################

print("\n\n----Leitura/Escrita Arquivos----")
with open("entrada.txt", "a+") as file:
    file.write("Escrevendo no arquivo\n")
file.close()

with open("entrada.txt", "r") as file:
    text = file.readlines()
file.close()
print(text)


######################################################################################
print("\n\n----Módulos----")

import math
print(math.sqrt(81))