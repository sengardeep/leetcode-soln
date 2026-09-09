class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        if (find(begin(wordList), end(wordList), endWord) == wordList.end())
            return 0;
        if (find(begin(wordList), end(wordList), beginWord) == wordList.end())
            wordList.push_back(beginWord);
        int n = wordList.size();
        vector<int> adj[n];
        int src = -1, dest = -1;
        for (int i = 0; i < n; i++) {
            string s = wordList[i];
            if (s == beginWord)
                src = i;
            if (s == endWord)
                dest = i;
            for (int j = 0; j != i && j < n; j++) {
                string t = wordList[j];
                int cnt = 0;
                for (int k = 0; k < t.size(); k++)
                    if (s[k] != t[k])
                        cnt++;
                if (cnt == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        queue<int> q;
        q.push(src);
        vector<int> vis(n);
        int ans = 0;
        while (!q.empty()) {
            int s = q.size();
            ans++;
            while (s--) {
                int node = q.front();
                if (node == dest)
                    return ans;
                q.pop();
                if (vis[node])
                    continue;
                vis[node] = 1;
                for (auto nb : adj[node]) {
                    if (!vis[nb]) {
                        q.push(nb);
                    }
                }
            }
        }
        return 0;
    }
};