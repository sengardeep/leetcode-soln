class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int> pi(n,-1);
        int k=-1;
        for(int i=1;i<n;i++){
            while(k>-1 && s[k+1]!=s[i]) k=pi[k];
            if(s[k+1]==s[i]) k++;
            pi[i]=k;
        }
        int mx=pi[n-1];
        string ans=s.substr(0,mx+1);
        return ans;
    }
};