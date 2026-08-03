class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int start=1;int end=*max_element(piles.begin(),piles.end());
        int ans=end;
        auto check = [&](int x){
            long long count=0;
            for(int i=0;i<n;i++){
                count += piles[i]/x;
                if(piles[i]%x) count++;
            }
            return count <= h;
        };
        while(start<=end){
            int mid = start + (end-start)/2;
            if(check(mid)){
                ans=mid;
                end=mid-1;
            }else start=mid+1;
        }
        return ans;
    }
};