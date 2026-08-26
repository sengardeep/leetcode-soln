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
    int rob(TreeNode* root) {
        function<pair<int,int>(TreeNode*)> f = [&](TreeNode* root){
            if(!root) return make_pair(0,0);
            auto left=f(root->left);
            auto right=f(root->right);
            
            int pick = root->val + left.second + right.second;
            int skip = max(left.first,left.second)+max(right.first,right.second);

            return make_pair(pick,skip);
        };

        auto ans = f(root);
        return max(ans.first,ans.second);
    }
};