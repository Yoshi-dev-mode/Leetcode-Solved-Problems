
# Checking if a binary tree is height-balanced in Python

class Node:
    def __init__(self, data):
        # Store the value of the current node.
        self.data = data

        # Every new node starts without left or right children.
        self.left = self.right = None


class Height:
    def __init__(self):
        # Store the height of a subtree.
        # Initially, its height is 0.
        self.height = 0


def isHeightBalanced(root, height):

    # Create separate objects to store the heights
    # of the left and right subtrees.
    left_height = Height()
    right_height = Height()

    # Base case: An empty tree is balanced.
    if root is None:
        return True

    # Recursively check whether the left subtree is balanced.
    # Its height will be stored in left_height.height.
    l = isHeightBalanced(root.left, left_height)

    # Recursively check whether the right subtree is balanced.
    # Its height will be stored in right_height.height.
    r = isHeightBalanced(root.right, right_height)

    # Calculate the height of the current subtree.
    # Height = the greater child height + 1 for the current node.
    height.height = max(
        left_height.height,
        right_height.height
    ) + 1

    # A tree is height-balanced if the difference between
    # the left and right subtree heights is at most 1.
    if abs(left_height.height - right_height.height) <= 1:

        # Both the left and right subtrees must also be balanced.
        return l and r

    else:
        # The height difference is greater than 1,
        # so the current subtree is not balanced.
        return False


# Create an object to store the height of the entire tree.
height = Height()

# Build the binary tree.
#
#           1
#          / \
#         2   3
#        / \
#       4   5

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

# Check whether the binary tree is height-balanced.
if isHeightBalanced(root, height):
    print('The tree is balanced')
else:
    print('The tree is not balanced')
