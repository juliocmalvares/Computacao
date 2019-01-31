
produtos = {}
prod = ''
with open('produtos.txt', 'r') as fl:
    for line in fl:
        #print(line)
        produtos[line.split()[0]] = line.split()[1:]

for key in produtos:
    for st in produtos[key]:
        prod += st + ' '
    produtos[key] = prod
    prod = ''

str_arq = ''
arquivo = ''
with open('input_apriori.csv', 'r') as file:
    arquivo = file.read()



for key in produtos:
    arquivo.replace(key, produtos[key])
    print(arquivo)

#     for line in file:
#         for item in line.split():
#             print(item, type(item))
#             try:
#                 line.replace(str(item), produtos[str(item)])
#             except:
#                 print("error")
#         str_arq += line

# print(str_arq)
