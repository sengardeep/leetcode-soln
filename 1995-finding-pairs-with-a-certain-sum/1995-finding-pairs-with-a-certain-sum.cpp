class FindSumPairs {
public:
    map<int, int> mp;
    vector<int> nums1;
    vector<int> nums2;
    FindSumPairs(vector<int>& arr1, vector<int>& arr2) {
        nums1 = arr1;
        nums2 = arr2;
        sort(nums1.begin(),nums1.end());
        for (auto it : nums2)
            mp[it]++;
    }

    void add(int index, int val) {
        int num = nums2[index];
        nums2[index]=num+val;
        mp[num]--;
        mp[num + val]++;
    }

    int count(int tot) {
        int ans = 0;
        for (auto it : nums1) {
            if (it > tot)
                break;
            int num = tot - it;
            ans += mp[num];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */