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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root)
            return {};
        queue<tuple<TreeNode*, int, int>> q;
        map<int, map<int, multiset<int>>> mp;
        q.push(make_tuple(root, 0, 0));
        while (!q.empty()) {
            tuple<TreeNode*, int, int> temp = q.front();
            int level = get<1>(temp);
            int v = get<2>(temp);
            TreeNode* curr = get<0>(temp);
            if (curr->left)
                q.push(make_tuple(curr->left, level + 1, v - 1));
            if (curr->right)
                q.push(make_tuple(curr->right, level + 1, v + 1));
            mp[v][level].insert(curr->val);
            q.pop();
        }
        vector<vector<int>> ans;
        for (auto it : mp) {
            vector<int> temp;
            for (auto q : it.second) {
                temp.insert(temp.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};