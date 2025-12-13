class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        map<string,vector<string>> mp;
        vector<string> v={"electronics","grocery","pharmacy","restaurant"};
        int n=code.size();
        for(int i=0;i<n;i++)
            {
                if(check(code[i]) && isActive[i] && code[i].size()>0)
                {
                    mp[businessLine[i]].push_back(code[i]);
                }
            }

        vector<string> ans;
        for(auto it : v){
            vector<string> temp=mp[it];
            sort(temp.begin(),temp.end());
            ans.insert(ans.end(),temp.begin(),temp.end());
        }
        // sort(ans.begin(),ans.end());
        return ans;
    }
private:
    bool check(string s)
    {
        for(auto it : s){
            if(!isalnum(it) && it != '_') return false;
        }

        return true;
    }
};