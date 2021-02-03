from node import Node

class Stack: # de cima pra baixo ==> o primeiro a entrar eh o ultimo a sair, o ultimo a entrar eh o primeiro a sair
    def __init__(self):
        self.top = None
        self._size = 0

    def push(self, elem): # O(1)
        # insere um elemento
        node = Node(elem)               
        node.next = self.top
        self.top = node
        self._size += 1

    def pop(self): # O(1)
        # remove um elemento
        if self._size > 0:
            elem = self.top.data
            self.top = self.top.next
            self._size -= 1
            return elem
        else:
            raise IndexError("the stack is empty")

    def peek(self): # O(1)
        # retorna o ultimo elemento, sem remove-lo
        if self._size > 0:
            return self.top.data
        else:
            raise IndexError("the stack is empty")

    def __len__(self):  # O(1)
        """ Retorna o tamanho da lista """
        return self._size

    def __repr__(self):
        r = ''
        pointer = self.top
        while pointer:
            r += str(pointer.data) + " -> "
            pointer = pointer.next
        return r

    def __str__(self):
        return self.__repr__()