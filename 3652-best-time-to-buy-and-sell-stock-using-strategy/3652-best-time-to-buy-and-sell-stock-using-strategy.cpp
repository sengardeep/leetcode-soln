class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long> pre(n,0);
        pre[0]=strategy[0]*prices[0];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+prices[i]*strategy[i];
        auto rangeRes=[&](int l,int r)->long long{
            long long ans=pre[r];
            return (l==0)?ans:ans-pre[l-1];
        };
        vector<long long> preSum(n,0);
        preSum[0]=prices[0];
        for(int i=1;i<n;i++) preSum[i]=preSum[i-1]+prices[i];
        auto rangeSum=[&](int l,int r)->long long{
            long long ans=preSum[r];
            return (l==0)?ans:ans-preSum[l-1];
        };
        long long ans=pre[n-1];
        for(int i=0;i+k-1<n;i++){
            int l=i,r=i+k-1;
            long long temp=pre[n-1]-rangeRes(l,r)+rangeSum((l+r+1)/2,r);
            ans=max(ans,temp);
        }
        return ans;
    }
};