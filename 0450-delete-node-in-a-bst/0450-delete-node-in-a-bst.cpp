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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;
        if (root->val == key)
            return attach(root);
        TreeNode* curr = root;
        while (curr) {
            if (curr->val > key) {
                if (curr->left != nullptr && curr->left->val == key) {
                    curr->left = attach(curr->left);
                    break;
                } else
                    curr = curr->left;
            } else {
                if (curr->right != nullptr && curr->right->val == key) {
                    curr->right = attach(curr->right);
                    break;
                } else
                    curr = curr->right;
            }
        }
        return root;
    }

private:
    TreeNode* attach(TreeNode* root) // Function to attach the right subtree
                                     // with left subtree
    {
        if (!root->right)
            return root->left;
        if (!root->left)
            return root->right;
        TreeNode* leftChild = root->left;
        TreeNode* lastLeft = leftMost(root->right);
        lastLeft->left = leftChild;
        return root->right;
    }
    TreeNode* leftMost(TreeNode* root) {
        if (root->left == NULL)
            return root;
        return leftMost(root->left);
    }
};