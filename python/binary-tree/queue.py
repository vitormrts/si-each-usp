class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.first = None
        self.last = None
        self._size = 0

    def push(self, elem): # O(1)
        # insere um elemento
        node = Node(elem)
        if self.last is None: # nao tem ultimo
            self.last = node
        else: # atualiza o ultimo
            self.last.next = node
            self.last = node

        if self.first is None:
            self.first = node

        self._size += 1

    def pop(self): # O(1)
        # remove um elemento
        if self.first is not None:
            elem = self.first.data
            self.first = self.first.next
            self._size -= 1
            return elem
        raise IndexError("The queue is empty.")

        

    def peek(self): # O(1)
        # retorna o ultimo elemento, sem remove-lo
        if self._size > 0:
            return self.first.data

    def __len__(self):  # O(1)
        """ Retorna o tamanho da lista """
        return self._size

    def __repr__(self):
        if self._size > 0:
            r = ''
            pointer = self.first
            while pointer:
                r = r + str(pointer.data) + " " 
                pointer = pointer.next
            return r
        raise IndexError("The queue is empty")

    def __str__(self):
        return self.__repr__()