class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a)
            pq.push({a, 'a'});
        if (b)
            pq.push({b, 'b'});
        if (c)
            pq.push({c, 'c'});
        string ans = "";
        while (pq.size() > 1) {
            auto [f1, ch1] = pq.top();
            pq.pop();
            auto [f2, ch2] = pq.top();
            pq.pop();
            if (!ans.empty() && ans.back() == ch1) {
                ans += ch1;
                f1--;
                ans += ch2;
                f2--;
            } else {
                if (f1 > 1){
                    ans += ch1;
                    ans += ch1;
                    f1 -= 2;
                }else  {
                    ans += ch1;
                    f1-=1;
                }
                ans += ch2;
                f2 -= 1;
            }
            if(f1>0)
            pq.push({f1, ch1});
            if(f2>0)
            pq.push({f2, ch2});
        }
        if (pq.size() == 1) {
            auto [f,c] = pq.top();
            if (f == 1) {
                ans += c;
            } else {
                ans += c;
                ans += c;
            }
        }
        return ans;
    }
};