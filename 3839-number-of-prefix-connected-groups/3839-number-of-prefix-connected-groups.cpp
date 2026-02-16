class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto s : words){
            if(s.size()<k) continue;
            mp[s.substr(0,k)]++;
        }
        int ans=0;
        for(auto [s,k] : mp) ans+=(k>1);
        return ans;
    }
};