class Solution {
public:
    vector<vector<string>> partition(string s) {
        auto check=[&](int l,int r){
            while(l<=r){
                if(s[l]!=s[r]) return 0;
                l++;
                r--;
            }
            return 1;
        };
        int n=s.size();
        vector<vector<string>> ans;
        vector<string> temp;
        function<void(int)> f=[&](int index){
            if(index==n) {
                ans.push_back(temp);
                return;
            }
            for(int i=index;i<n;i++){
                if(check(index,i)){
                    string t = s.substr(index,i-index+1);
                    temp.push_back(t);
                    f(i+1);
                    temp.pop_back();
                }
            }
        };
        f(0);
        return ans;
    }
};