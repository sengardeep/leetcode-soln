/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root)
            return {};
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            if (temp->left) {
                q.push(temp->left);
                parent[temp->left] = temp;
            }
            if (temp->right) {
                q.push(temp->right);
                parent[temp->right] = temp;
            }
            q.pop();
        }
        q.push(target);
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
            while (!q.empty()) {
                if(k==0) break;
                int size=q.size();
                while(size--)
                {
                TreeNode* temp = q.front();
                if (temp->left != nullptr && visited[temp->left] != true) {
                    visited[temp->left] = true;
                    q.push(temp->left);
                }
                if (temp->right != nullptr && visited[temp->right] != true) {
                    visited[temp->right] = true;
                    q.push(temp->right);
                }
                if (parent.find(temp) != parent.end() &&
                    visited[parent[temp]] != true) {
                    visited[parent[temp]] = true;
                    q.push(parent[temp]);
                }
                q.pop();
                }
                k-=1;
            }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};