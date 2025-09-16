class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int curr = -1;
        for (int i = 0; i < n; i++) {
            if (curr == -1)
                curr = nums[i];
            else {
                if (gcd(curr, nums[i]) > 1) {
                    curr = lcm(curr, nums[i]);
                } else {
                    while (!ans.empty()) {
                        int num = ans.back();
                        if (gcd(curr, num) > 1) {
                            ans.pop_back();
                            curr = lcm(curr, num);
                        } else {
                            ans.push_back(curr);
                            curr = -1;
                            break;
                        }
                    }
                    if (curr != -1)
                        ans.push_back(curr);
                    curr = nums[i];
                }
            }
        }
        while (!ans.empty()) {
            int num = ans.back();
            if (gcd(curr, num) > 1) {
                ans.pop_back();
                curr = lcm(curr, num);
            } else {
                ans.push_back(curr);
                curr = -1;
                break;
            }
        }
        if(curr != -1)
        ans.push_back(curr);
        return ans;
    }

private:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
};