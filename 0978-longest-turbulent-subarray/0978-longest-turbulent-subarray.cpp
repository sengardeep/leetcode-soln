class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1, n = arr.size();
        int flag = 0;
        auto comp = [&](int x, int y) {
            if (flag)
                return (x > y);
            else
                return (x < y);
        };
        for (int i = 0; i + 1 < n; i++) {
            if (arr[i] < arr[i + 1]) {
                flag = 1;
                int j = i + 1;
                while (j + 1 < n) {
                    if (comp(arr[j], arr[j + 1])) {
                        j++;
                        flag ^= 1;
                    } else
                        break;
                }
                ans = max(ans, j - i + 1);
                i = j - 1;
            } else if (arr[i] > arr[i + 1]) {
                flag = 0;
                int j = i + 1;
                while (j + 1 < n) {
                    if (comp(arr[j], arr[j + 1])) {
                        j++;
                        flag ^= 1;
                    } else
                        break;
                }
                ans = max(ans, j - i + 1);
                i = j - 1;
            }
        }
        return ans;
    }
};