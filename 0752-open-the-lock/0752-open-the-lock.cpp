class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> vis(deadends.begin(), deadends.end());
        if(vis.count("0000") || vis.count(target)) return -1;
        queue<string> q;
        q.push("0000");
        vis.insert("0000");
        int ans = 0;
        while (!q.empty()) {
            int k = q.size();
            while (k--) {
                string s = q.front();
                q.pop();
                if (s == target)
                    return ans;
                for (int i = 0; i < 4; i++) {
                    char c = s[i];
                    int x = c - '0';
                    c = ((x + 1) % 10) + '0';
                    string t = s;
                    t[i] = c;
                    if (vis.count(t) == 0) {
                        q.push(t);
                        vis.insert(t);
                    }
                    c = ((x - 1 + 10) % 10) + '0';
                    t[i] = c;
                    if (vis.count(t) == 0) {
                        q.push(t);
                        vis.insert(t);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};