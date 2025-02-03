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
    int maxPathSum(TreeNode* root) {
        int ans = -1000;
        int x = solve(root, ans);
        return ans;
    }

private:
    int solve(TreeNode* root, int& ans) {
        if (!root)
            return 0;
        int left = solve(root->left, ans);
        int right = solve(root->right, ans);
        if(left<0) left=0;
        if(right<0) right=0;
        ans = max(ans, root->val + left + right);
        return root->val + max(left, right);
    }
};