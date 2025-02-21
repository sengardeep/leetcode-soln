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
class FindElements {
public:
    unordered_map<int ,bool> mp;
    FindElements(TreeNode* root) {
        makeTree(root,0);
    }
    
    bool find(int target) {
        return (mp.find(target)!=mp.end());
    }
private:
    void makeTree(TreeNode* root,int x)
    {
        if(!root) return;
        root->val=x;
        mp[x]=true;
        makeTree(root->left,2*x+1);
        makeTree(root->right,2*x+2);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */