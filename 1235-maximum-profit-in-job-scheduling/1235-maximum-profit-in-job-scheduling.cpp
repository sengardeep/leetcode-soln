class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<tuple<int,int,int>> jobs;
        for(int i=0;i<n;i++) jobs.push_back({startTime[i],endTime[i],profit[i]});
        sort(begin(jobs),end(jobs));
        vector<int> dp(n,0),suffMax(n+1,0);
        auto lower_bound = [&](int x){
            int start=0,end=n-1;
            while(start<=end){
                int mid = end + (start-end)/2;
                auto [s,e,p] = jobs[mid];
                if(s>=x) end=mid-1;
                else start=mid+1;
            }
            return start;
        };
        for(int i=n-1;i>=0;i--){
            auto [s,e,p] = jobs[i];
            int lb = lower_bound(e);
            dp[i] = p+suffMax[lb];
            suffMax[i]=max(suffMax[i+1],dp[i]);
        }
        return *max_element(begin(dp),end(dp));
    }
};