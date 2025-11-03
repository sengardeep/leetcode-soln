class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int ans=0,mx=0;
        for(int i=1;i<n;i++){
            if(colors[i]==colors[i-1]) 
            {
                if(mx==0){
                    ans+=neededTime[i-1];
                    mx=max(mx,neededTime[i-1]);
                }
                ans+=neededTime[i];
                mx=max(mx,neededTime[i]);
            }
            else {
                ans-=mx;
                mx=0;
            }
        }
        ans-=mx;
        return ans;
    }
};