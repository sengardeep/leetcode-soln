class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> freq(26, 0);
        int ans = 0;
        function<int(int)> f = [&](int index) {
            if (index == n)
                return accumulate(freq.begin(), end(freq), 0);
            int ans = f(index + 1);
            int flag = 1;
            unordered_set<char> st;
            for (auto c : arr[index]) {
                if (freq[c - 'a'] || st.count(c)) {
                    flag = 0;
                    break;
                }
                st.insert(c);
            }
            if (flag) {
                for(auto c : arr[index]) freq[c-'a']++;
                ans = max(ans, f(index + 1));
                for(auto c : arr[index]) freq[c-'a']--;
            }
            return ans;
        };
        return f(0);
    }
};