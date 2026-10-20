
# LeetCode 144: Binary Tree Preorder Traversal
# Approach: Recursion (Depth-First Search)
# Order: Root -> Left -> Right

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        """
        Initialize a tree node.

        Args:
            val (int): Value stored in the node.
            left (TreeNode): Reference to the left child.
            right (TreeNode): Reference to the right child.
        """
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def preorderTraversal(self, root):
        """
        Return the preorder traversal of a binary tree.

        Preorder visits nodes in this order:
        1. Root
        2. Left subtree
        3. Right subtree

        Args:
            root (TreeNode): The root of the binary tree.

        Returns:
            List[int]: Node values in preorder traversal order.

        Time Complexity: O(n)
            Each node is visited exactly once.

        Space Complexity: O(n)
            Stores the result and uses recursion.
        """

        # Base case: An empty subtree has no values.
        if root is None:
            return []

        # Step 1: Visit the root first.
        res = [root.val]

        # Step 2: Collect values from the left subtree.
        res += self.preorderTraversal(root.left)

        # Step 3: Collect values from the right subtree.
        res += self.preorderTraversal(root.right)

        # Return all values in preorder order.
        return res


def main():
    """
    Create a sample binary tree, run preorder traversal,
    and print the resulting list.

              1
             / \
            2   3
           / \
          4   5
    """

    # Build the tree from the bottom up.
    node4 = TreeNode(4)
    node5 = TreeNode(5)
    node2 = TreeNode(2, node4, node5)
    node3 = TreeNode(3)
    root = TreeNode(1, node2, node3)

    # Create a Solution object.
    solution = Solution()

    # Perform preorder traversal.
    result = solution.preorderTraversal(root)

    # Display the result.
    print("Preorder Traversal:", result)


# Run main() only when this file is executed directly.
if __name__ == "__main__":
    main()
