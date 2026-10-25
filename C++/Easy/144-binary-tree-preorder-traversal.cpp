/*
 * Problem: 144. Binary Tree Preorder Traversal
 * Platform: LeetCode
 * Difficulty: Easy
 *
 * Description:
 * Given the root of a binary tree, return the preorder traversal
 * of its nodes' values.
 *
 * Preorder Traversal:
 * Visit the nodes in the following order:
 * 1. Root
 * 2. Left Subtree
 * 3. Right Subtree
 *
 * Approach: Recursion
 *
 * How it works:
 * 1. If the current node is nullptr, return an empty vector.
 * 2. Store the current node's value in the result vector.
 * 3. Recursively traverse the left subtree and append its values.
 * 4. Recursively traverse the right subtree and append its values.
 * 5. Return the combined result.
 *
 * Time Complexity: O(n)
 * Each node is visited once, where n is the number of nodes.
 *
 * Space Complexity: O(n)
 * The result vector stores n node values. Recursive calls also
 * use stack space proportional to the tree's height.
 *
 * Note:
 * The recursive calls create intermediate vectors, which are
 * copied into the result vector using insert().
 */

#include <iostream>
#include <vector>
using namespace std;

// Definition of a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor for a node with no children.
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        // Base case: an empty tree has no nodes to visit.
        if (root == nullptr) {
            return {};
        }

        // Create a vector to store the traversal result.
        vector<int> res;

        // Step 1: Visit the root.
        res.push_back(root->val);

        // Step 2: Traverse the left subtree recursively.
        vector<int> left = preorderTraversal(root->left);

        // Append the left subtree's values to the result.
        res.insert(res.end(), left.begin(), left.end());

        // Step 3: Traverse the right subtree recursively.
        vector<int> right = preorderTraversal(root->right);

        // Append the right subtree's values to the result.
        res.insert(res.end(), right.begin(), right.end());

        // Return the preorder traversal.
        return res;
    }
};

// Main function for local testing.
int main() {

    /*
     * Construct the following binary tree:
     *
     *         1
     *        / \
     *       2   3
     *      / \
     *     4   5
     *
     * Expected preorder traversal:
     * 1 2 4 5 3
     */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Create an instance of the solution class.
    Solution solution;

    // Perform preorder traversal.
    vector<int> result = solution.preorderTraversal(root);

    // Display the result.
    cout << "Preorder Traversal: ";

    for (int value : result) {
        cout << value << " ";
    }

    cout << endl;

    // Free the allocated memory.
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}