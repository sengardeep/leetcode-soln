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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return solve(preorder,idx,1001);
    }
private:
    TreeNode* solve(vector<int>& pre,int &idx,int bound)
    {
        if(idx==pre.size() || pre[idx] > bound) return nullptr;
        TreeNode* root=new TreeNode(pre[idx++]);
        root->left=solve(pre,idx,root->val);
        root->right=solve(pre,idx,bound);
        return root;
    }
};