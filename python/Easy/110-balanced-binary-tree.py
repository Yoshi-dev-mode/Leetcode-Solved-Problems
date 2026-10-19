
# ============================================================
# LeetCode 110: Balanced Binary Tree
# Topic: Binary Trees | Recursion | Depth-First Search (DFS)
# ============================================================
#
# Time Complexity:  O(n)
# Space Complexity: O(h)
#
# A binary tree is height-balanced if, for EVERY node,
# the difference between the heights of its left and
# right subtrees is at most 1.
#
# ============================================================


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val        # Value stored in the node
        self.left = left      # Reference to the left child
        self.right = right    # Reference to the right child


class Solution(object):
    def isBalanced(self, root):
        """
        Determine whether a binary tree is height-balanced.

        Args:
            root (TreeNode): The root node of the binary tree.

        Returns:
            bool: True if the tree is balanced, False otherwise.
        """

        def getHeight(node):
            # BASE CASE:
            # An empty subtree has a height of 0.
            if node is None:
                return 0

            # STEP 1:
            # Calculate the height of the left subtree.
            left_height = getHeight(node.left)

            # If the left subtree is unbalanced, stop early.
            if left_height == -1:
                return -1

            # STEP 2:
            # Calculate the height of the right subtree.
            right_height = getHeight(node.right)

            # If the right subtree is unbalanced, stop early.
            if right_height == -1:
                return -1

            # STEP 3:
            # Check whether the subtree heights differ by more than 1.
            if abs(left_height - right_height) > 1:
                return -1

            # STEP 4:
            # Return the height of the current subtree.
            return max(left_height, right_height) + 1

        # A return value of -1 means the tree is unbalanced.
        # Any other value means the tree is balanced.
        return getHeight(root) != -1


# ============================================================
# MAIN: TEST CASES
# ============================================================

def main():
    solution = Solution()

    # --------------------------------------------------------
    # TEST CASE 1: Balanced Binary Tree
    # --------------------------------------------------------
    #
    #          3
    #         / \
    #        9   20
    #           /  \
    #          15   7
    #
    # Expected Output: True
    # Explanation:
    # Every node has a left/right subtree height difference
    # of at most 1.
    # --------------------------------------------------------

    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)

    result = solution.isBalanced(root)

    print("Test Case 1: Balanced Binary Tree")
    print("Output:", result)
    print("Expected: True")
    print("-" * 40)

    # --------------------------------------------------------
    # TEST CASE 2: Empty Binary Tree
    # --------------------------------------------------------
    #
    # An empty tree is considered balanced.
    #
    # Expected Output: True
    # --------------------------------------------------------

    root = None

    result = solution.isBalanced(root)

    print("Test Case 2: Empty Binary Tree")
    print("Output:", result)
    print("Expected: True")
    print("-" * 40)

    # --------------------------------------------------------
    # TEST CASE 3: Unbalanced Binary Tree
    # --------------------------------------------------------
    #
    #       1
    #      /
    #     2
    #    /
    #   3
    #
    # Expected Output: False
    # Explanation:
    # Node 1 has a left subtree of height 2 and a right
    # subtree of height 0. The difference is greater than 1.
    # --------------------------------------------------------

    root = TreeNode(1)
    root.left = TreeNode(2)
    root.left.left = TreeNode(3)

    result = solution.isBalanced(root)

    print("Test Case 3: Unbalanced Binary Tree")
    print("Output:", result)
    print("Expected: False")
    print("-" * 40)


# Run the test cases when this file is executed directly.
if __name__ == "__main__":
    main()
