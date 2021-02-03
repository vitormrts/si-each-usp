from queue import Queue

ROOT = 'root'

class Node:
    def __init__(self, data):
        self.data = data
        self.right = None
        self.left = None

    def __str__(self): # qnd Node eh convertido pra string, ele devolve o dado
        return str(self.data) 

class BinaryTree:
    def __init__(self, data=None, node=None):
        if node:
            self.root = node
        if data:
            node = Node(data)
            self.root = node
        else:
            self.root = None

    def pre_order(self, node=None):
        if node is None:
            node = self.root
        print(node, end=' ')
        if node.left:
            return pre_order(node.left)
        if node.right:
            return pre_order(node.right)

    # percurso em ordem simetrica
    def in_order(self, node=None):
        if node is None: # se o usuario nao insere o no, iniciamos da raiz
            node = self.root
        if node.left: 
            # print('(', end='')
            self.in_order(node.left)
        print(node, end=' ')
        if node.right:
            self.in_order(node.right)
            # print(')', end='')
        
    def post_order(self, node=None):
        if node is None:
            node = self.root
        if node.left:
            self.post_order(node.left)
        if node.right:
            self.post_order(node.right)
        print(node)

    def level_order(self, node=ROOT):
        if node == ROOT:
            node = self.root
        
        queue = Queue()
        queue.push(node)
        while len(queue):
            node = queue.pop()
            if node.left:
                queue.push(node.left)
            if node.right:
                queue.push(node.right)
            print(node, end=' ')
            

    def height(self, node=None):
        if node is None:
            node = self.root
        hleft = 0
        hright = 0
        if node.left:
            hleft = self.height(node.left)
        if node.right:
            hright = self.height(node.right)
        if hleft > hright:
            return hleft + 1
        return hright + 1

class BinarySearchTree(BinaryTree):
    def insert(self, value):
        parent = None
        x = self.root
        while x:
            parent = x
            if value < x.data:
                x = x.left
            else:
                x = x.right
        if parent is None:
            self.root = Node(value)
        elif value < parent.data:
            parent.left = Node(value)
        else:
            parent.right = Node(value)

    def search(self, value, node=0):
        if node == 0:
            node = self.root
        if node is None:
            return node
        if node.data == value:
            return BinarySearchTree(node)
        if value < node.data:
            return self.search(value, node.left)
        return self.search(value, node.right)

    def min(self, node=ROOT):
        if node == ROOT:
            node = self.root
        while node.left:
            node = node.left
        return node.data
    
    def max(self, node=ROOT):
        if node == ROOT:
            node = self.root
        while node.right:
            node = node.right
        return node.data

    def remove(self, value, node=ROOT):
        if node == ROOT:
            node = self.root
        
        if node is None:
            return node
        
        if value < node.data:
            node.left = self.remove(value, node.left)
        elif value > node.data:
            node.right = self.remove(value, node.right)
        else:
            # CASO 1 ==> no folha
            # if node.left is None and node.right is None:
            #     return None

            # CASO 2 ==> no com um filho
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left
            # CASO 3 ==> no com 2 filhos 
            else:
                substitute = self.min(node.right)
                node.data = substitute
                node.right = self.remove(substitute, node.right)

        return node 


        
    