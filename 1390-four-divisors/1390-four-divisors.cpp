class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(auto x : nums){
            unordered_set<int> set;
            for(int i=2;i*i<=x;i++){
                if(x%i==0) {
                    set.insert(i);
                    set.insert(x/i);
                }
            }
            set.insert(1);
            set.insert(x);
            if(set.size()==4) {
                for(auto it :  set) ans+=it;
            }
        }
        return ans;
    }
};