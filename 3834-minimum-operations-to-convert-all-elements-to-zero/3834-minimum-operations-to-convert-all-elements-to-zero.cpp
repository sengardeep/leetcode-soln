class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> stack;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (!stack.empty() && stack.top() > nums[i]) {
                ans++;
                stack.pop();
            }
            while (!stack.empty() && stack.top() == nums[i])
                stack.pop();
            stack.push(nums[i]);
        }
        while (!stack.empty()) {
            if (stack.top() != 0)
                ans++;
            stack.pop();
        }
        return ans;
    }
};