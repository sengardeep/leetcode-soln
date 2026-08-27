class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> mp(26,0);
        for(int i=0;i<26;i++) mp[order[i]-'a']=i;
        for(int i=0;i+1<words.size();i++){
            string s=words[i],t=words[i+1];
            int j=0,n=s.size(),m=t.size();
            int flag=1;
            while(j<min(n,m)){
                if(mp[s[j]-'a'] > mp[t[j]-'a']) return 0;
                if(s[j]!=t[j]){ 
                    flag=0;
                    break;    
                }
                j++;
            }
            if(flag && n>m) return 0;

        }
        return 1;
    }
};