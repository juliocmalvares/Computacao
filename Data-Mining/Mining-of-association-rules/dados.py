import dbfread as dr
records = [p for p in dr.DBF('vendas.dbf')]
print("Quantidade de registros: ", len(records))

records = [dict(p) for p in records]

print(type(records[0]))

db_sequencias = []

for record in records:
    db_sequencias.append(record)

produtos = []

for record in db_sequencias:
    produtos.append([record['PRODUTO'], record['OPERACAO']])

print("Quantiadde de itens",len(produtos))

dataset = {}
for record in produtos:
    dataset[record[1]] = []
for record in produtos:
    dataset[record[1]].append(record[0])

cont = 0
line = ''
with open('input_apriori.csv', 'w') as fl:
    for key in dataset:
        cont+=1
        for produto in dataset[key]:
            line += str(produto) + ' '
        line += '\n'
        fl.write(line)
        line = ''
print(cont)

dataset2 = {}
for key in dataset:
    if len(dataset[key]) != 1:
        dataset2[key] = dataset[key]




cont = 0
line = ''
with open('input_apriori2.csv', 'w') as fl:
    for key in dataset2:
        cont+=1
        for produto in dataset2[key]:
            line += str(produto) + ' '
        line += '\n'
        fl.write(line)
        line = ''
