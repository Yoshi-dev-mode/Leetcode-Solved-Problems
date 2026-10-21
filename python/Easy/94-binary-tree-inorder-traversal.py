# Definition for a binary tree node.
class TreeNode(object):
    """
    Represents a node in a binary tree.

    Attributes:
        val: The value stored in the node.
        left: Reference to the left child.
        right: Reference to the right child.
    """
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    """
    LeetCode 94: Binary Tree Inorder Traversal

    Approach: Recursive Depth-First Search (DFS)

    Inorder traversal visits nodes in this order:
        1. Left subtree
        2. Current node (root)
        3. Right subtree

    Time Complexity: O(n)
        Each node is visited exactly once.

    Space Complexity: O(n)
        Stores the traversal result and uses the recursion stack.
    """

    def inorderTraversal(self, root):
        """
        Traverses the binary tree using inorder traversal.

        Args:
            root (TreeNode): The root of the binary tree.

        Returns:
            list[int]: The node values in inorder sequence.
        """

        # Base case: an empty subtree has no values.
        if root is None:
            return []

        # Store the values collected during traversal.
        res = []

        # Step 1: Visit the left subtree.
        res += self.inorderTraversal(root.left)

        # Step 2: Visit the current node.
        res += [root.val]

        # Step 3: Visit the right subtree.
        res += self.inorderTraversal(root.right)

        # Return the values in inorder sequence.
        return res


# Main function: test the solution locally.
def main():
    """
    Builds a sample binary tree and prints its inorder traversal.

            1
             \
              2
             /
            3
    """

    # Create the sample binary tree.
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)

    # Create an instance of Solution.
    solution = Solution()

    # Perform inorder traversal.
    result = solution.inorderTraversal(root)

    # Display the result.
    print("Inorder Traversal:", result)


# Run main() only when this file is executed directly.
if __name__ == "__main__":
    main()
