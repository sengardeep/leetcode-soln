/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        function<void(TreeNode*)> f = [&](TreeNode* root){
            if(!root) return;
            f(root->left);
            inorder.push_back(root->val);
            f(root->right);
        };
        f(root);
        for(int i=0;i+1<inorder.size();i++) if(inorder[i+1]<=inorder[i]) return 0;
        return 1;
    }
};