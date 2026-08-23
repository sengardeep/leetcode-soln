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
    int goodNodes(TreeNode* root) {
        int ans=0;
        function<void(TreeNode*,int)> f = [&](TreeNode* root,int mx){
            if(!root) return;
            if(root->val >= mx){
                ans++;
            }
            f(root->left,max(mx,root->val));
            f(root->right,max(mx,root->val));
        };
        f(root,-1e5);
        return ans;
    }
};