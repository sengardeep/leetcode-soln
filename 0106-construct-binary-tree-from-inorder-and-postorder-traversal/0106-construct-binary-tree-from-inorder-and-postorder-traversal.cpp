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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(inorder, 0, inorder.size() - 1, postorder, 0,
                     postorder.size() - 1, mp);
    }

private:
    TreeNode* build(vector<int>& in, int inStart, int inEnd, vector<int>& post,
                    int postStart, int postEnd, unordered_map<int, int>& mp) {
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;

        TreeNode* root = new TreeNode(post[postEnd]);
        int inRoot = mp[root->val];
        int left = inRoot - inStart;
        root->left = build(in, inStart, inRoot - 1, post, postStart,
                           postStart + left - 1, mp);
        root->right = build(in, inRoot + 1, inEnd, post, postStart + left,
                            postEnd - 1, mp);
        return root;
    }
};