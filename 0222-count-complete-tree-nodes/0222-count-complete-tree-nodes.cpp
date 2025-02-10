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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int leftH=l(root);
        int rightH=r(root);
        if(leftH==rightH) return (1<<leftH)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
private:
    int l(TreeNode* root)
    {
        int ans=0;
        while(root)
        {
            ans++;
            root=root->left;
        }
        return ans;
    }
    int r(TreeNode* root)
    {
        int ans=0;
        while(root)
        {
            ans++;
            root=root->right;
        }
        return ans;
    }
};