#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    /**
     * Returns the postorder traversal of a binary tree.
     *
     * Traversal order: Left -> Right -> Root
     *
     * @param root Pointer to the root of the current subtree.
     * @return Vector containing the node values in postorder.
     */
    vector<int> postorderTraversal(TreeNode *root)
    {

        // Base case: An empty subtree has no node values.
        if (root == nullptr)
        {
            return {};
        }

        // Store the postorder traversal of the current subtree.
        vector<int> res;

        // Step 1: Recursively traverse the left subtree.
        vector<int> left = postorderTraversal(root->left);

        // Append the left subtree's values to the result.
        res.insert(res.end(), left.begin(), left.end());

        // Step 2: Recursively traverse the right subtree.
        vector<int> right = postorderTraversal(root->right);

        // Append the right subtree's values to the result.
        res.insert(res.end(), right.begin(), right.end());

        // Step 3: Visit the current root after both subtrees.
        res.push_back(root->val);

        // Return the completed postorder traversal.
        return res;
    }
};