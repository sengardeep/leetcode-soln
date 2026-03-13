class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long start=1,end=5000050000000000;
        long long ans=end;
        auto check = [&](long long k){
            long long h=0;
            for(int x : workerTimes){
                long long start=0,end=1e5;
                long long ans=0;
                while(start<=end){
                    long long mid = end + (start-end)/2;
                    long long time = (mid*(mid+1)/2)*x;
                    if(time <= k) {
                        ans=mid;
                        start=mid+1;
                    }else end=mid-1;
                }
                h += ans;
            }
            return h>=mountainHeight;
        };
        while(start<=end){
            long long mid = end + (start-end)/2;
            if(check(mid)) {
                ans=mid;
                end=mid-1;
            }else start=mid+1;
        }
        return ans;
    }
};