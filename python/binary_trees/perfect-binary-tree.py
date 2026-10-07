# Checking if a binary tree is a perfect binary tree in Python

class newNode:
    def __init__(self, k):
        self.key = k
        self.right = self.left = None

# calculate the depth of the tree
def calculateDepth(node):
    if node is None:
        return 0
    left_depth = calculateDepth(node.left)
    right_depth = calculateDepth(node.right)
    return max(left_depth, right_depth) + 1

# check if the tree is a perfect binary tree
def is_perfect(root, d, level=0):
    # check if the tree is empty
    if root is None:
        return True

    # check the presence of leaves
    if root.left is None and root.right is None:
        return d == level + 1

    if root.left is None or root.right is None:
        return False

    return is_perfect(root.left, d, level + 1) and is_perfect(root.right, d, level + 1)

root = newNode(1)
root.left = newNode(2)
root.right = newNode(3)
root.left.left = newNode(4)
root.left.right = newNode(5)
root.right.left = newNode(6)
root.right.right = newNode(7)

if is_perfect(root, calculateDepth(root)):
    print("The tree is a perfect binary tree")
else:
    print("The tree is not a perfect binary tree")