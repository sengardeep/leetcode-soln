class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int mod = 1e9+7;
        vector<int> occ(31,0);
        for(auto x : nums){
            for(int i=0;i<=30;i++){
                if(x&(1<<i)) occ[i]++;
            }
        }
        long long ans = 0;
        while(k--){
            int num = 0;
            for(int i=0;i<=30;i++){
                if(occ[i]>0){
                    num |= (1<<i);
                    occ[i]--;
                }
            }
            ans = (ans + (num*1LL*num)%mod)%mod;
        }
        return ans;
    }
};