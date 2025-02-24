class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        if(k==0) return 0;
        priority_queue<int, vector<int>, greater<int>> p;
        for (int i = 0; i < grid.size(); i++) {
            priority_queue<int, vector<int>, greater<int>> temp;
            if(limits[i]==0) continue;
            for (int j = 0; j < grid[i].size(); j++) {
                if (j < limits[i])
                    temp.push(grid[i][j]);
                else {
                    if (temp.top() < grid[i][j]) {
                        temp.pop();
                        temp.push(grid[i][j]);
                    }
                }
            }
            while (!temp.empty()) {
                if (p.size() < k) {
                    p.push(temp.top());
                } else {
                    if (temp.top() > p.top()) {
                        p.pop();
                        p.push(temp.top());
                    }
                }
                temp.pop();
            }
        }
        long long ans = 0;
        while (!p.empty()) {
            ans += p.top();
            p.pop();
        }
        return ans;
    }
};