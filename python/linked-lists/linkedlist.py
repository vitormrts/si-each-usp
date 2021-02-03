from node import Node

# sequencial = []
# sequencial.append()

# Lista Ligada


class LinkedList:
    def __init__(self):  # Construtor
        self.head = None  # primeiro elemento da lista
        self._size = 0  # tamanho da lista

    def append(self, elem):  # O(n)
        """ Adiciona um elemento ao fim da lista"""
        if self.head:  # lista ja tem elementos
            pointer = self.head
            while pointer.next:
                pointer = pointer.next
            pointer.next = Node(elem)
        else:  # primeira insercao
            self.head = Node(elem)
        self._size += 1

    def __len__(self):  # O(1)
        """ Retorna o tamanho da lista """
        return self._size

    def get(self, index):
        # lista.get(index)
        pass

    def _getnode(self, index):
        pointer = self.head
        for i in range(index):
            if pointer:
                pointer = pointer.next
            else:
                raise IndexError("list index out of range")
        return pointer

    def set(self, index, elem):
        # lista.set(index, item)
        pass

    def __getitem__(self, index):  # O(n)
        # a = lista[index]
        """ Retorna o item no indice desejado """
        pointer = self._getnode(index)
        if pointer:
            return pointer.data
        raise IndexError("list index out of range")

    def __setitem__(self, index, elem):  # O(n)
        # lista[index] = item
        """ Insere o elemento no indice desejado  """
        pointer = self._getnode(index)
        if pointer:
            pointer.data = elem
        else:
            raise IndexError("list index out of range")

    def index(self, elem):  # O(n)
        """ Retorna o indice do elemento na lista """
        pointer = self.head
        i = 0
        while pointer:
            if pointer.data == elem:
                return i
            pointer = pointer.next
            i += 1
        raise ValueError("{} is not in list".format(elem))

    def insert(self, index, elem):
        node = Node(elem)
        if index == 0: # insercao no comeco da lista ==> O(1)
            node.next = self.head
            self.head = node
        else: # insercao apos o inicio ==> O(n)
            pointer = self._getnode(index-1) # queremos o ponteiro anterior
            node.next = pointer.next
            pointer.next = node
        self._size += 1

    def remove(self, elem):
        if self.head == None:
            raise ValueError("{} is not in list".format(elem))
        elif self.head.data == elem: # exclui o primeiro elemento
            self.head = self.head.next
            return True
        else:
            ancestor = self.head
            pointer = self.head.next
            while pointer:
                if pointer.data == elem:
                    ancestor.next = pointer.next
                    pointer.next = None
                ancestor = pointer
                pointer = pointer.next
            self._size -= 1
            return True
        raise ValueError("{} is not in list".format(elem))

    def __repr__(self):
        r = ''
        pointer = self.head
        while pointer:
            r += str(pointer.data) + " -> "
            pointer = pointer.next
        return r

    def __str__(self):
        return self.__repr__()

    def removedouble(self):
        pointer = self.head
        while pointer:
            nextelem = pointer.next
            while nextelem and nextelem.data == pointer.data:
                nextelem = nextelem.next
            pointer.next = nextelem
            pointer = nextelem
        return self 

    

    lista = LinkedList()
    lista.append(1)
    lista.append(1)
    lista.append(2)
    lista.append(2)
    lista.append(3)
    lista.append(4)
    lista.removedouble()


