class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int res = 0;
        
        vector<vector<int>> memo(n, vector<int>(6005, -1));

        function<int(int)> f = [&](int index){
            if(index == n){
                if(res >= 0) return res;
                return (int)1e5;
            }
            
            if(memo[index][res + 3000] != -1) {
                return memo[index][res + 3000];
            }

            res += stones[index];
            int plus = f(index + 1);
            res -= stones[index];
            
            res -= stones[index];
            int neg = f(index + 1);
            res += stones[index];
            
            return memo[index][res + 3000] = min(plus, neg);
        };
        
        return f(0);
    }
};