class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> p;
    int size=p.size();
    KthLargest(int k, vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (i < k)
                p.push(nums[i]);
            else {
                int top = p.top();
                if (top < nums[i]) {
                    p.pop();
                    p.push(nums[i]);
                }
            }
        }
        size=k;
    }

    int add(int val) {
        if (p.size() < size) {
            p.push(val);
            return p.top();
        }
        int top = p.top();
        if (top < val) {
            p.pop();
            p.push(val);
        }
        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */