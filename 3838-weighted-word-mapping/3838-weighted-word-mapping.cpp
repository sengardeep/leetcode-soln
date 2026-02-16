class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto s : words){
            int x=0;
            for(auto c : s) x+=weights[c-'a'];
            x%=26;
            ans+=('a'+(25-x));
        }
        return ans;
    }
};