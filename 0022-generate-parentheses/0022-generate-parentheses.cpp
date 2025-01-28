class Solution {
public: 
    void generate(int n,int left,int right,string &temp,vector<string>&ans)
    {
        if(left+right==2*n)
        {
            ans.push_back(temp);
            return;
        }

        if(left<n)
        {
            temp+='(';
            generate(n,left+1,right,temp,ans);
            temp.pop_back();
        }

        if(right<left)
        {
            temp+=')';
            generate(n,left,right+1,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> ans;
        generate(n,0,0,temp,ans);
        return ans;
    }
};