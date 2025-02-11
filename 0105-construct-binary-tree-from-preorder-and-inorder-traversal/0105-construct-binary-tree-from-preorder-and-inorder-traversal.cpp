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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0,
                     inorder.size() - 1, mp);
    }

private:
    TreeNode* build(vector<int>& pre, int preStart, int preEnd, vector<int>& in,
                    int inStart, int inEnd, unordered_map<int, int>& mp) {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        int inRoot = mp[pre[preStart]];
        int left = inRoot - inStart;
        TreeNode* root = new TreeNode(pre[preStart]);

        root->left = build(pre, preStart + 1, preStart + left, in, inStart,
                           inRoot - 1, mp);
        root->right =
            build(pre, preStart + left + 1, preEnd, in, inRoot+1, inEnd, mp);
        return root;
    }
};