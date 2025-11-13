class Solution {
public:
    int maxOperations(string s) {
        int ans=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') count++;
            else 
            {
                ans+=count;
                while(i<s.size() && s[i]=='0') i++;
                i--;
            }
        }
        return ans;
    }
};