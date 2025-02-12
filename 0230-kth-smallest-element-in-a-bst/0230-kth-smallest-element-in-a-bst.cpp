/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int count = 0; // Counter for visited nodes

    int kthSmallest(TreeNode* root, int k) {
        TreeNode* result = helper(root, k);
        return result ? result->val : 0; // Return value or 0 if not found
    }

    TreeNode* helper(TreeNode* root, int k) {
        if (root == nullptr)
            return nullptr;

        // Traverse left subtree
        TreeNode* left = helper(root->left, k);
        if (left != nullptr)
            return left; // If found in left subtree

        count++; // Increment count for current node
        if (count == k)
            return root; // Found k-th smallest

        // Traverse right subtree
        return helper(root->right, k);
    }
};