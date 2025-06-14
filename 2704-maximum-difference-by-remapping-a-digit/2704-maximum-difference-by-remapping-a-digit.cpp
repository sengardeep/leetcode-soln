class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        char c;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='9')
            {
             c=s[i];
             break;
            }
        }
        string maxi=s;
        for(int i=0;i<s.size();i++) if(maxi[i]==c) maxi[i]='9';

        c=s[0];
        string mini=s;
        for(int i=0;i<s.size();i++) if(mini[i]==c) mini[i]='0';

        int ans=stoi(maxi)-stoi(mini);
        return ans;
    }
};