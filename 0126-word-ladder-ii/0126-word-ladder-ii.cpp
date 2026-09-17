class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        map<string, int> level;
        queue<string> q;
        unordered_set<string> list(begin(wordList), end(wordList));
        q.push(beginWord);
        level[beginWord] = 0;
        if (list.count(beginWord))
            list.erase(list.find(beginWord));
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            for (int i = 0; i < s.size(); i++) {
                string temp = s;
                for (int j = 0; j < 26; j++) {
                    s[i] = 'a' + j;
                    if (list.count(s)) {
                        q.push(s);
                        level[s] = level[temp] + 1;
                        list.erase(list.find(s));
                    }
                }
                s = temp;
            }
        }

        vector<vector<string>> ans;
        function<void(string, vector<string>)> dfs = [&](string s,
                                                         vector<string> seq) {
            if (s == beginWord) {
                reverse(begin(seq),end(seq));
                ans.push_back(seq);
                return;
            }
            for (int i = 0; i < s.size(); i++) {
                string temp = s;
                for (int j = 0; j < 26; j++) {
                    s[i] = 'a' + j;
                    if (level.count(s) && level[temp] == level[s] + 1) {
                        seq.push_back(s);
                        dfs(s, seq);
                        seq.pop_back();
                    }
                }
                s = temp;
            }
            return;
        };
        dfs(endWord, {endWord});
        return ans;
    }
};