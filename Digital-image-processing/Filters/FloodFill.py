#!/usr/bin/python3
import imageio
import numpy as np

class Node(object):
    def __init__(self, data):
        if type(data) == tuple:
            self.dado = data
            self.x = self.dado[0]
            self.y = self.dado[1]
    
    def get_data(self):
        return self.dado
    
    def get_x(self):
        return self.x
    
    def get_y(self):
        return self.y

    def __str__(self):
        return  str(self.dado)

class Stack(object):
    def __init__(self):
        self.head = None
        self.tail = None
        self.nodes = list()
        self.len = 0

    def add(self, dado):
        if type(dado) == Node:
            self.nodes.append(dado)
            if self.len == 0:
                self.head = self.tail = self.nodes[0]
                self.len += 1
            else:
                self.tail = self.nodes[-1]
                self.len += 1
        else:
            print('Tipo incorreto, adição não feita')
    
    def remove(self):
        if self.len > 1:
            aux =  self.nodes.pop(0)
            self.head = self.nodes[0]
            self.len -= 1
            return aux
        else:
            print('Stack vazia!')
    
    def __str__(self):
        return 'Stack: ' + str(self.nodes)

class FloodFill(object):
    def __init__(self, name_img):
        self.color = 0
        self.img = np.array(imageio.imread(name_img))
        self.old_color = self.color
        self.vizinhos = Stack()
    
    def expand_node(self, x, y):
        self.old_color = self.img[x][y][0]
        aux_x = x
        flag = True
        while x > 0 and flag:
            if self.img[x][y][0] == self.old_color:    
                self.vizinhos.add(Node((x, y)))
                x-=1
            else:
                flag = False
        
        flag = True
        x = aux_x
        # len(self.img) retorna o y
        # len(self.img[0]) retorna o x
        while x < len(self.img[0]) and flag:
            if self.img[x][y][0] == self.old_color:    
                self.vizinhos.add(Node((x, y)))
                x+=1
            else:
                flag = False

    
    def apply(self, x, y, new_color):
        pass


# fl = FloodFill('cat.png')
# fl.apply(5,5, 10)

fl = FloodFill('cat.png')
fl.expand_node(90,120)
print(fl.vizinhos.len)
"""
    Floodfill é o baldinho do gimp.
    O objetivo é expandir um nó no grafo por todas as direções e, enquanto a cor da aresta for diferente da old_cor, trocar pra nova cor
"""