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
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                temp.push_back(curr->val);
            }
            if (flag) {
                flag = false;
            } else {
                flag = true;
                reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};