class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

    def traversePreOrder(self):
        print(self.val, end=" ")
        if self.left:
            self.left.traversePreOrder()
        if self.right:
            self.right.traversePreOrder()

    def traverseInOrder(self):
        if self.left:
            self.left.traverseInOrder()
        print(self.val, end=" ")
        if self.right:
            self.right.traverseInOrder()

    def traversePostOrder(self):
        if self.left:
            self.left.traversePostOrder()
        if self.right:
            self.right.traversePostOrder()
        print(self.val, end=" ")

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)

print("PreOrder:",end=" ")
root.traversePreOrder()
print("InOrder:",end=" ")
root.traverseInOrder()
print("PostOrder:",end=" ")
root.traversePostOrder()        