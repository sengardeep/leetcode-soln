class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        if(num*9 < sum) return ans;
        while(num--){
            int x = min(9,sum);
            sum -= x;
            ans += (x+'0');
        }
        return ans;
    }
};