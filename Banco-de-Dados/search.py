	def search(self, key):
		aux = self
		n = list()
		while aux.get_flagLeaf() is not True:
			sons = sons(aux)
			if sons > 0:
				i = 0
				while i < sons:
					if key is not aux[i].get_key():
						n.append(aux[i])
					elif key > aux[i-1].get_key():
						n.append(aux[i])
					else:
						j=1
						while aux[j] is None:
							if aux[i-1] < key and aux[i-1] is not key:
								n.append(aux[i])
							j+=1
					i+=1

			page = n[len(n)-1].descendent
			i = 0
			while page[i].key is not key:
				i+=1
			if page[i].key is key:
				return page[i]
			else:
				print("\nDeu ruim jhow!, Registro não encontrado!! \n")