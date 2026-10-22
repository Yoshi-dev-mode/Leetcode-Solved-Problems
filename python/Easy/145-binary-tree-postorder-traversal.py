
# ============================================================
# LeetCode 145: Binary Tree Postorder Traversal
# ============================================================
# Approach: Recursion (Depth-First Search)
#
# Postorder Traversal Order:
#   1. Left Subtree
#   2. Right Subtree
#   3. Root Node
#
# Example Binary Tree:
#
#          1
#           \
#            2
#           /
#          3
#
# Postorder Output: [3, 2, 1]
#
# Time Complexity: O(n)
#   - Each node is visited exactly once.
#
# Space Complexity: O(n)
#   - Stores the traversal result and uses the
#     recursion call stack.
# ============================================================


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        """Initialize a tree node with a value and child nodes."""
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def postorderTraversal(self, root):
        """
        Return the postorder traversal of a binary tree.

        Postorder means:
            Left -> Right -> Root

        Args:
            root (TreeNode): The root node of the binary tree.

        Returns:
            List[int]: Node values in postorder sequence.
        """

        # Base case: An empty subtree has no node values.
        if root is None:
            return []

        # Create a list to store the traversal result.
        result = []

        # Step 1: Visit the entire left subtree.
        result += self.postorderTraversal(root.left)

        # Step 2: Visit the entire right subtree.
        result += self.postorderTraversal(root.right)

        # Step 3: Visit the current root node last.
        result += [root.val]

        # Return the completed traversal for this subtree.
        return result


# ============================================================
# Main Function: Test the Solution
# ============================================================
def main():
    # Construct the following binary tree:
    #
    #        1
    #         \
    #          2
    #         /
    #        3
    #
    # Expected postorder traversal: [3, 2, 1]

    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)

    # Create an instance of the Solution class.
    solution = Solution()

    # Execute postorder traversal.
    output = solution.postorderTraversal(root)

    # Display the result.
    print("Postorder Traversal:", output)


# Run the main function when this file is executed directly.
if __name__ == "__main__":
    main()
