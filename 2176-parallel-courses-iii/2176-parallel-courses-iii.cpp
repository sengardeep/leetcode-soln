class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int ans = 0;
        vector<int> inDeg(n, 0);
        vector<int> adj[n];
        for (auto it : relations) {
            adj[it[0] - 1].push_back(it[1] - 1);
            inDeg[it[1] - 1]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (inDeg[i] == 0)
                q.push(i);
        vector<int> courseTime(n, 0);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int top = q.front();
                q.pop();
                for (int i = 0; i < adj[top].size(); i++) {
                    int num = adj[top][i];
                    inDeg[num]--;

                    //Maximum Time to complete current + prev course time
                    courseTime[num] =
                        max(courseTime[num], time[top] + courseTime[top]);
                    if (inDeg[num] == 0)
                        q.push(num);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            ans = max(ans, time[i] + courseTime[i]);
        }
        return ans;
    }
};