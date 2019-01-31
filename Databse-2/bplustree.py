#BPluss Tree


class Node(object):
	def __init__(self, data = None, index = None, root = False, quantum_fields = 25):
		self.index = list()
		self.data = list()
		self.children = list()
		self.root = False
		self.leaf = True
		self.next = None
		self.previous = None
		self.blockTam = 1000
		self.quantum_fields = quantum_fields
		self.full = int(self.blockTam/int(self.quantum_fields*4))
		self.void = int(int(self.blockTam/2)/(self.quantum_fields))

	def isRoot(self):
		return self.root

	def isLeaf(self):
		return self.leaf

	def filled(self):
		return len(self.data) == self.full

	def minimum(self):
		return len(self.data) <= self.void

	def innerNodeFull(self):
		return len(self.index) == int(self.full*self.quantum_fields)

	def innerNodeisEmpty(self):
		return len(self.index) <= int(self.void*self.quantum_fields)

	def search(self, node, key):
		if node.isLeaf():
			for i in range(len(node.data)):
				if node.data[i] == key:
					return node
		else:





'''
node = Node(quantum_fields = 25)
node.data.append(0)
node.data.append(10)
node.data.append(2)
for i in range(len(node.data)):
	print("Data: "+str(node.data[i]))
aux = node.search(node, 10)

if aux is node:
	print("Uhul")
	'''