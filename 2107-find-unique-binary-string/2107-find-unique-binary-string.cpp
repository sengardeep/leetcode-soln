class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        vector<string> ans;
        string temp;
        generate(ans,temp,n);
        for(auto it : ans) 
        {
            if(find(nums.begin(),nums.end(),it)==nums.end()) return it;
        }
        return "";
    }
private:
    void generate(vector<string> &ans,string &temp,int n)
    {
        if(temp.size()==n) 
        {
            ans.push_back(temp);
            return;
        }
        temp+='0';
        generate(ans,temp,n);
        temp.pop_back();
        temp+='1';
        generate(ans,temp,n);
        temp.pop_back();
    }
};