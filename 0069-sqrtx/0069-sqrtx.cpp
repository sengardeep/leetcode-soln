class Solution {
public:
    int mySqrt(int x) {
        int start = 1, end = x, ans = 0;
        while (start <= end) {
            int mid = end + (start - end) / 2;
            long long sq = mid *1LL* mid;
            if (sq == x)
                return mid;
            else if (sq < x) {
                ans = mid;
                start = mid + 1;
            } else
                end = mid - 1;
        }
        return ans;
    }
};