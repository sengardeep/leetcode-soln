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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        long long ans = 0;
        if (!root)
            return 0;
        q.push({root, 0});
        while (!q.empty()) {
            long long first, last;
            long long size = q.size();
            long long extra = q.front().second;
            for (long long i = 0; i < size; i++) {
                TreeNode* curr = q.front().first;
                long long id = q.front().second - extra;
                if (i == 0)
                    first = id;
                if (i == size - 1)
                    last = id;
                if (curr->left)
                    q.push({curr->left, id * 2 + 1});
                if (curr->right)
                    q.push({curr->right, id * 2 + 2});
                q.pop();
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};