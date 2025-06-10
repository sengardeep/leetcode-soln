class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(auto it : s) mp[it]++;
        int maxEven=0,maxOdd=0,minEven=101,minOdd=101;
        for(auto it : mp)
            {
                if(it.second&1) 
                {
                    maxOdd=max(maxOdd,it.second);
                    minOdd=min(minOdd,it.second);
                }
                else
                {
                    maxEven=max(maxEven,it.second);
                    minEven=min(minEven,it.second);
                }
            }
        int ans;
        if(maxOdd!=0 && minEven!=101)
        {
            ans=(maxOdd-minEven);
        }
        return ans;
    }
};