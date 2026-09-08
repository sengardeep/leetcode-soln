/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<int, Node*> mp;
        queue<Node*> q;

        Node* root = new Node(node->val);
        mp[node->val] = root;

        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            Node* clone = mp[curr->val];

            for (Node* x : curr->neighbors) {

                if (!mp.count(x->val)) {
                    mp[x->val] = new Node(x->val);
                    q.push(x);
                }

                clone->neighbors.push_back(mp[x->val]);
            }
        }

        return root;
    }
};