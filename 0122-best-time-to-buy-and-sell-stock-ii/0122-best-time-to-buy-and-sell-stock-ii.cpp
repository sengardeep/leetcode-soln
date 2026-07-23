class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0,mn=1e9;
        for(int i=0;i<n;i++){
            if(prices[i]-mn>0){
                ans+=prices[i]-mn;
                mn=1e9;
            }
            mn=min(mn,prices[i]);
        }
        return ans;
    }
};