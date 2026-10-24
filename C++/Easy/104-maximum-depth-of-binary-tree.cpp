#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with a value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with a value and child nodes
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * Calculates the maximum depth of a binary tree.
     *
     * @param root Pointer to the root node of the binary tree.
     * @return The number of nodes along the longest root-to-leaf path.
     */
    int maxDepth(TreeNode* root) {

        // Base case: An empty tree has a depth of 0.
        if (root == nullptr) {
            return 0;
        }

        // Recursively calculate the maximum depth of the left subtree.
        int left = maxDepth(root->left);

        // Recursively calculate the maximum depth of the right subtree.
        int right = maxDepth(root->right);

        // Add 1 for the current node to the greater subtree depth.
        return 1 + max(left, right);
    }
};

int main() {
    /*
             1
            / \
           2   3
          /
         4

        Expected maximum depth: 3
    */

    // Create the binary tree.
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    // Create a Solution object.
    Solution solution;

    // Calculate and display the maximum depth.
    cout << "Maximum Depth: " << solution.maxDepth(root) << endl;

    // Expected output: Maximum Depth: 3

    // Free the allocated memory.
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}