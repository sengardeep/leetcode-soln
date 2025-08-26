class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        auto pythagoras=[](int a,int b){
            return (a*a+b*b);
        };
        int ans=0,d=0;
        for(auto it : dimensions){
            int temp = pythagoras(it[0],it[1]);
            if(temp>d){
                d=temp;
                ans=it[0]*it[1];
            }
            else if(temp==d) ans=max(ans,it[0]*it[1]);
        }

        return ans;
        
    }
};