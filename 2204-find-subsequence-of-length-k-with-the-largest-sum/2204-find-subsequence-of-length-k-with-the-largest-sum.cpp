class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == n)
            return nums;

        vector<int> temp = nums;

        // Partial Sort(O(n))
        nth_element(
            begin(temp), begin(temp) + k - 1, end(temp),
            greater<int>()); // Fit the kth largest element on the kth position
                             // and put greater on left and shorter on right

        int countK = 0, el = temp[k - 1];
        for (int i = 0; i < k; i++)
            countK += (temp[i] == el);

        temp.clear();

        for (int i = 0; i < n; i++) {
            if (nums[i] > el)
                temp.push_back(nums[i]);
            else if (countK && nums[i] == el) {
                countK--;
                temp.push_back(nums[i]);
            }
        }

        return temp;
    }
};