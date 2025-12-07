class Solution {
public:
    int countOdds(int low, int high) {
        auto f=[&](int n){
            return (n+1)/2;
        };
        int ans=f(high);
        if(low>0) ans-=f(low-1);
        return ans;
    }
};