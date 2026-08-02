class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, ans = nums[0];
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] >= nums[0]) {
                if (target > nums[mid])
                    start = mid + 1;
                else {
                    if (target >= nums[0])
                        end = mid - 1;
                    else
                        start = mid + 1;
                }
            } else {
                if (target < nums[mid])
                    end = mid - 1;
                else {
                    if (target < nums[0])
                        start = mid + 1;
                    else
                        end = mid - 1;
                }
            }
        }
        return -1;
    }
};