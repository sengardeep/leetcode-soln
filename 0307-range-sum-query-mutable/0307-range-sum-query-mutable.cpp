class NumArray {
    vector<int> segTree;
    vector<int> arr;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        arr = nums;
        segTree.assign(4 * n, -1);
        build(0, n - 1, 1);
    }

    void update(int index, int val) {
        int n = arr.size();
        function<void(int, int, int, int, int)> f =
            [&](int start, int end, int index, int pos, int val)->void {
            if (start == end) {
                if (pos == start) {
                    arr[pos] = val;
                    segTree[index] = val;
                }
                return;
            }

            if (pos > end || pos < start)
                return;
            int mid = (start + end) / 2;
            f(start, mid, 2 * index, pos, val);
            f(mid + 1, end, 2 * index + 1, pos, val);
            segTree[index] = segTree[2 * index] + segTree[2 * index + 1];
        };

        f(0, n - 1, 1, index, val);
    }

    int sumRange(int left, int right) {
        int n = arr.size();
        function<int(int, int, int, int, int)> f =
            [&](int start, int end, int index, int l, int r)->int {
            if (l <= start && r >= end)
                return segTree[index]; // total overlap
            if (l > end || r < start)
                return 0; // no overlap

            int mid = (start + end) / 2;

            int left = f(start, mid, 2 * index, l, r);
            int right = f(mid + 1, end, 2 * index + 1, l, r);

            return left + right;
        };

        return f(0, n - 1, 1, left, right);
    }

private:
    void build(int start, int end, int index) {
        if (start == end) {
            segTree[index] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        segTree[index] = segTree[2 * index] + segTree[2 * index + 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */