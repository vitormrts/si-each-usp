from tree import BinaryTree, Node, BinarySearchTree
import random

random.seed(2)

def inorder_example():
    tree = BinaryTree()
    n1 = Node('a')
    n2 = Node('+')
    n3 = Node('*')
    n4 = Node('b')
    n5 = Node('-')
    n6 = Node('/')
    n7 = Node('c')
    n8 = Node('d')
    n9 = Node('e ')

    n6.left = n7
    n6.right = n8
    n5.left = n6
    n5.right = n9
    n3.left = n4
    n3.right = n5
    n2.left = n1
    n2.right = n3

    tree.root = n2

    return tree

def postorder_example():
    tree = BinaryTree()
    n1 = Node('I')
    n2 = Node('N')
    n3 = Node('S')
    n4 = Node('C')
    n5 = Node('R')
    n6 = Node('E')
    n7 = Node('V')
    n8 = Node('A')
    n9 = Node('5')
    ntraco = Node('-')
    n0 = Node('3')

    n0.left = n6
    n0.right = n9
    n6.left = n1
    n6.right = n5
    n5.left = n2
    n5.right = n4
    n4.right = n3
    n9.left = n8
    n9.right = ntraco
    n8.right = n7


    tree.root = n0

    return tree

def random_tree():
    items = [1, 29, 1000, 892, 979]
    values = random.sample(range(1, 1000), 42)
    bst = BinarySearchTree()
    for v in values:
        bst.insert(v)
    return tree 

def example_tree():
    values = [61, 89, 66, 43, 51, 16, 55, 11, 79, 77, 82, 32]
    tree = BinarySearchTree()
    for v in values:
        tree.insert(v)
    return tree

bst = example_tree()
bst.in_order()
print("\n----")


if __name__ == '__main__':
    # tree_inorder = inorder_example()
    # tree_postorder = postorder_example()
    # print("Percurso em ordem: ")
    # tree_inorder.in_order()

    # print("\nPercurso pos-ordem: ")
    # tree_postorder.post_order()
    # print("Altura: ", tree_postorder.height())

    # for item in items:
    #     r = bst.search(item)
    #     if r:
    #         print(r.root.data, " encontrado")
    #     else:
    #         print(item, " nao encontrado")

    #bst.level_order()
    print(bst.min())
    print(bst.max())