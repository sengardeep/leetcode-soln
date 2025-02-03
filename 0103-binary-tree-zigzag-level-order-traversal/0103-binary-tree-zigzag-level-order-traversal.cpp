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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        vector<vector<int>> ans;
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp(size);
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                int idx = (flag) ? i : size - i - 1;
                temp[idx] = curr->val;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            flag = !flag;
            ans.push_back(temp);
        }
        return ans;
    }
};