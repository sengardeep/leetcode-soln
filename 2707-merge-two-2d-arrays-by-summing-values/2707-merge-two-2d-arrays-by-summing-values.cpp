class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int it1 = 0, it2 = 0;
        while ((it1 < nums1.size()) && (it2 < nums2.size())) {
            // Lesser
            while ((it1 < nums1.size() && it2 < nums2.size()) &&
                   (nums1[it1][0] < nums2[it2][0])) {
                ans.push_back(nums1[it1]);
                it1++;
            }
            // Equal
            while ((it1 < nums1.size()) && (it2 < nums2.size()) &&
                   (nums1[it1][0] == nums2[it2][0])) {
                ans.push_back({nums1[it1][0], nums1[it1][1] + nums2[it2][1]});
                it1++;
                it2++;
            }
            // Greater
            while ((it2 < nums2.size() && it1 < nums1.size()) &&
                   (nums1[it1][0] > nums2[it2][0])) {
                ans.push_back(nums2[it2]);
                it2++;
            }
        }
        while (it1 < nums1.size()) {
            ans.push_back(nums1[it1]);
            it1++;
        }
        while (it2 < nums2.size()) {
            ans.push_back(nums2[it2]);
            it2++;
        }
        return ans;
    }
};