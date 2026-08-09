class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        function<void(int)> f=[&](int i){
            if(temp.size()==k) {
                ans.push_back(temp);
                return;
            }
            if(i>n) return;
            temp.push_back(i);
            f(i+1);
            temp.pop_back();
            f(i+1);
        };
        f(1);
        return ans;
    }
};