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
        function<TreeNode*(TreeNode*)> f = [&](TreeNode* node){
            if(node==p || node==q || !node) return node;
            TreeNode* left=f(node->left),*right=f(node->right);
            if(left && right) return node;
            else return (left!=nullptr) ? left : (right!=nullptr ? right : nullptr); 
        };
        return f(root);
    }
};