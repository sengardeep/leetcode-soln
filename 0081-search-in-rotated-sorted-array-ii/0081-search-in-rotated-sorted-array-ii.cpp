class Solution {
public:
    bool search(vector<int>& nums, int target) {
        vector<int> temp;
        for(int i=0;i<nums.size();i++)
        if(temp.empty() || temp.back()!=nums[i] || temp[0]!=nums[i]) temp.push_back(nums[i]);
        nums.clear();
        nums=temp;
        int start = 0, end = nums.size() - 1, ans = nums[0];
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return 1;
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
        return 0;
    }
};