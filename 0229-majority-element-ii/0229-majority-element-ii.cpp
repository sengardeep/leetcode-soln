class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int x1 = -1e9 - 1, c1 = 0, x2 = -1e9 - 1, c2 = 0;
        for (int x : nums) {
            if (x == x1)
                c1++;
            else if (x == x2)
                c2++;
            else if (c1 == 0) {
                x1 = x;
                c1 = 1;
            } else if (c2 == 0) {
                x2 = x;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        for (int x : nums) {
            if (x == x1)
                c1++;
            else if (x == x2)
                c2++;
        }
        vector<int> ans;
        if (c1 > (n / 3))
            ans.push_back(x1);
        if (c2 > (n / 3))
            ans.push_back(x2);
        return ans;
    }
};