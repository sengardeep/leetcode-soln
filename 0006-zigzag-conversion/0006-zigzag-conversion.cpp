class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int down=2*numRows-2,n=s.size();
        string ans="";
        int idx=0;
        while(idx<n)
        {
            ans+=s[idx];
            idx+=down;
        }
        int up=2;
        down=down-2;
        for(int i=1;i<numRows-1;i++)
        {
            int j=i;
            bool flag=true;
            while(j<n)
            {
                ans+=s[j];
                if(flag)
                {
                    j+=down;
                    flag=false;
                }
                else
                {
                    j+=up;
                    flag=true;
                }
            }
            up+=2;
            down-=2;
        }
        idx=numRows-1;
        while(idx<n)
        {
            ans+=s[idx];
            idx+=up;
        }

        return ans;
    }
};