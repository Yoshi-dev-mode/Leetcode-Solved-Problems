#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 *
 * Each node contains:
 * - val: The value stored in the node.
 * - left: Pointer to the left child.
 * - right: Pointer to the right child.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor for an empty node.
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor for a node with a value.
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor for a node with a value and two children.
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * Performs inorder traversal of a binary tree.
     *
     * Inorder traversal follows this order:
     * 1. Visit the left subtree.
     * 2. Visit the current node.
     * 3. Visit the right subtree.
     *
     * @param root Pointer to the root of the binary tree.
     * @return A vector containing node values in inorder sequence.
     *
     * Time Complexity: O(n)
     *   Each node is visited once. However, this implementation
     *   creates and copies intermediate vectors during recursion.
     *   For a highly skewed tree, the total copying cost can
     *   reach O(n^2).
     *
     * Auxiliary Space: O(n)
     *   Stores the traversal results and uses a recursive call stack.
     */
    vector<int> inorderTraversal(TreeNode* root) {

        // Base case: An empty subtree has no values to visit.
        if (root == nullptr) {
            return {};
        }

        // Stores the inorder traversal of the current subtree.
        vector<int> res;

        // Step 1: Traverse the left subtree.
        vector<int> left = inorderTraversal(root->left);

        // Append the left subtree's values to the result.
        res.insert(res.end(), left.begin(), left.end());

        // Step 2: Visit the current node.
        res.push_back(root->val);

        // Step 3: Traverse the right subtree.
        vector<int> right = inorderTraversal(root->right);

        // Append the right subtree's values to the result.
        res.insert(res.end(), right.begin(), right.end());

        // Return the complete inorder traversal.
        return res;
    }
};

/**
 * Helper function to print the traversal result.
 */
void printVector(const vector<int>& values) {
    cout << "[";

    for (int i = 0; i < values.size(); i++) {
        cout << values[i];

        // Print a comma only between elements.
        if (i < values.size() - 1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

int main() {

    /*
     * Example binary tree:
     *
     *         1
     *          \
     *           2
     *          /
     *         3
     *
     * Expected inorder traversal:
     * [1, 3, 2]
     */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Create an instance of Solution.
    Solution solution;

    // Perform inorder traversal.
    vector<int> result = solution.inorderTraversal(root);

    // Display the result.
    cout << "Inorder Traversal: ";
    printVector(result);

    // Free the dynamically allocated memory.
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
