"""
LeetCode 100: Same Tree
Difficulty: Easy
Topic: Binary Tree, Depth-First Search (DFS), Recursion

Problem:
Given the roots of two binary trees p and q, determine if they are
the same tree.

Two binary trees are considered the same if:
1. They have the same structure.
2. Every corresponding node has the same value.

Approach: Recursive DFS
- If both nodes are None, they are identical.
- If only one node is None, the trees are different.
- If their values differ, the trees are different.
- Otherwise, recursively compare their left and right subtrees.

Time Complexity: O(n)
    Each node is visited at most once, where n is the number of nodes
    in the smaller tree.

Space Complexity: O(h)
    The recursion stack uses space proportional to the tree height h.
    In the worst case, h = n for a skewed tree.
"""


# Definition for a binary tree node.
class TreeNode(object):
    """Represents a node in a binary tree."""

    def __init__(self, val=0, left=None, right=None):
        self.val = val      # Value stored in the node
        self.left = left    # Reference to the left child
        self.right = right  # Reference to the right child


class Solution(object):
    def isSameTree(self, p, q):
        """
        Compare two binary trees recursively.

        Args:
            p (TreeNode): Root of the first binary tree.
            q (TreeNode): Root of the second binary tree.

        Returns:
            bool: True if both trees have identical structures
                  and corresponding node values; otherwise False.
        """

        # Base case 1:
        # If both nodes are None, their subtrees are identical.
        if p is None and q is None:
            return True

        # Base case 2:
        # If only one node is None, the structures are different.
        if p is None or q is None:
            return False

        # Base case 3:
        # If the node values differ, the trees are not identical.
        if p.val != q.val:
            return False

        # Recursive case:
        # Both current nodes match, so compare their left subtrees
        # AND their right subtrees.
        return (
            self.isSameTree(p.left, q.left)
            and self.isSameTree(p.right, q.right)
        )


def main():
    """Test the isSameTree solution with sample binary trees."""

    solution = Solution()

    # Example 1:
    # Tree p:       1
    #              / \
    #             2   3
    #
    # Tree q:       1
    #              / \
    #             2   3
    #
    # Expected output: True

    p = TreeNode(1, TreeNode(2), TreeNode(3))
    q = TreeNode(1, TreeNode(2), TreeNode(3))

    result1 = solution.isSameTree(p, q)
    print("Example 1:", result1)

    # Example 2:
    # Tree p:       1
    #              /
    #             2
    #
    # Tree q:       1
    #                \
    #                 2
    #
    # Expected output: False
    # The structures are different.

    p = TreeNode(1, TreeNode(2), None)
    q = TreeNode(1, None, TreeNode(2))

    result2 = solution.isSameTree(p, q)
    print("Example 2:", result2)

    # Example 3:
    # Tree p:       1
    #              /
    #             2
    #
    # Tree q:       1
    #              /
    #             3
    #
    # Expected output: False
    # The corresponding child nodes have different values.

    p = TreeNode(1, TreeNode(2), None)
    q = TreeNode(1, TreeNode(3), None)

    result3 = solution.isSameTree(p, q)
    print("Example 3:", result3)


# Run the test cases when this file is executed directly.
if __name__ == "__main__":
    main()
