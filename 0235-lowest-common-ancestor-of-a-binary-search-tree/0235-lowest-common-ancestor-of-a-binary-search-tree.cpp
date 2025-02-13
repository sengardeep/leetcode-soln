/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val)
                root = root->left; // Both nodes are in the left subtree
            else if (p->val > root->val && q->val > root->val)
                root = root->right; // Both nodes are in the right subtree
            else
                return root; // This is the LCA
        }
        return nullptr;
    }
};