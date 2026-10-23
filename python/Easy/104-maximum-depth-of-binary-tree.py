"""
LeetCode 104: Maximum Depth of Binary Tree

Problem:
Given the root of a binary tree, return its maximum depth.

The maximum depth is the number of nodes along the longest path
from the root node down to the farthest leaf node.

Approach: Recursion (Depth-First Search)

Explanation:
1. If the current node is None, return 0.
2. Recursively calculate the maximum depth of the left subtree.
3. Recursively calculate the maximum depth of the right subtree.
4. Return 1 plus the greater of the two depths.

Time Complexity: O(n)
    Each node is visited once, where n is the number of nodes.

Space Complexity: O(h)
    The recursive call stack uses space proportional to the tree's
    height, where h is the height of the tree.
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root):
        """
        Calculates the maximum depth of a binary tree.

        Args:
            root (TreeNode): The root node of the binary tree.

        Returns:
            int: The maximum depth of the tree.
        """

        # Base case: An empty tree has a depth of 0.
        if root is None:
            return 0

        # Recursively calculate the maximum depth of the left subtree.
        left_depth = self.maxDepth(root.left)

        # Recursively calculate the maximum depth of the right subtree.
        right_depth = self.maxDepth(root.right)

        # Count the current node and add the greater subtree depth.
        return 1 + max(left_depth, right_depth)


# Main function for local testing.
def main():
    """
    Creates a sample binary tree, calculates its maximum depth,
    and prints the result.
    """

    # Construct the following binary tree:
    #
    #         3
    #        / \
    #       9   20
    #          /  \
    #         15   7
    #
    # Expected maximum depth: 3

    root = TreeNode(
        3,
        TreeNode(9),
        TreeNode(
            20,
            TreeNode(15),
            TreeNode(7)
        )
    )

    # Create a Solution object and calculate the maximum depth.
    solution = Solution()
    result = solution.maxDepth(root)

    # Display the result.
    print("Maximum Depth:", result)


# Run the main function when this file is executed directly.
if __name__ == "__main__":
    main()


# Expected Output:
# Maximum Depth: 3