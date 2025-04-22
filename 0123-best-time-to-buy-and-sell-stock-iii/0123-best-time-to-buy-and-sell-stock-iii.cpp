class Solution{
public:
    int maxProfit(vector<int> arr){
        int n=arr.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(arr,dp,0,1,n,2);
    }
private:
    int helper(vector<int> &arr,vector<vector<vector<int>>> &dp,int idx,int buy,int n,int count)
    {
        if(idx==n || count==0) return 0;
        if(dp[idx][buy][count] != -1) return dp[idx][buy][count];

        int profit = 0;
        if(buy) //We have option to buy a stock
        {
            profit = max((-arr[idx]+helper(arr,dp,idx+1,0,n,count)),(helper(arr,dp,idx+1,1,n,count)));
        }
        else
        {
            profit = max((arr[idx]+helper(arr,dp,idx+1,1,n,count-1)),helper(arr,dp,idx+1,0,n,count));
        }

        return dp[idx][buy][count] = profit;
    }
};
