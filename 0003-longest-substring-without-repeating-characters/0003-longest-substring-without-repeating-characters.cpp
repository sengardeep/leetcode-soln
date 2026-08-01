class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int ans=0;
        set<char> vis;
        while(j<s.size()){
            while(vis.count(s[j])){
                vis.erase(vis.find(s[i]));
                i++;
            }
            ans=max(ans,j-i+1);
            vis.insert(s[j]);
            j++;
        }
        return ans;
    }
};