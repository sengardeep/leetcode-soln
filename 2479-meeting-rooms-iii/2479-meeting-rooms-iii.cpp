class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());
        vector<int> meet(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq; // Priority Queue will store endTime along with room number

        priority_queue<int, vector<int>, greater<int>> available;

        for (int i = 0; i < n; i++)
            available.push(i);
        // for (int i = 0; i < n; i++)
        //     pq.push({0, i});

        for (auto it : meetings) {
            int start = it[0], end = it[1];

            while (!pq.empty() && pq.top().first <= start) {
                available.push(pq.top().second);
                pq.pop();
            }

            if (!available.empty()) {
                int room = available.top();
                pq.push({end, room});
                available.pop();
                meet[room]++;
            } else {
                auto p = pq.top();
                long long room = p.second, time = p.first;
                pq.pop();
                time += (end-start);
                pq.push({time, room});
                meet[room]++;
            }
        }

        int maxi = -1, ans = -1;
        for (int i = 0; i < n; i++) {
            if (maxi < meet[i]) {
                maxi = meet[i];
                ans = i;
            }
        }

        return ans;
    }
};