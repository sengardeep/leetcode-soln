class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        for(int i=1;i<strs.size();i++)
        {
            string temp="";
            int j=0;
            while(j<strs[i].size() && j<ans.size() && strs[i][j]==ans[j])
            temp+=strs[i][j++];

            ans=temp;
        }
        return ans;
    }
};