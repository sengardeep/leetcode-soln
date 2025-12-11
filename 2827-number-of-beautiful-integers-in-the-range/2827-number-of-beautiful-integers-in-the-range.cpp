class Solution {
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string s=to_string(high);
        int ans=helper(s,k);
        low-=1;
        s=to_string(low);
        ans-=helper(s,k);
        return ans;
    }
private:
    int helper(string s,int k){
        map<tuple<int,int,int,int,int,int>, int> dp;
        function<int(int,int,int,int,int,int)> f=[&](int index,int kMod,int even,int odd,int isTight,int isLeading)->int{
            if(index==s.size()) return (!(kMod)&&even==odd);
            auto key = make_tuple(index, kMod, even, odd, isTight, isLeading);
            auto it = dp.find(key);
            if (it != dp.end()) return it->second;

            int ans=0;
            for(int d=0;d<=(isTight?(s[index]-'0'):9);d++){
                int e=even,o=odd;
                if(isLeading || d) {
                    if(d%2) o++;
                    else e++;
                }
                ans+=f(index+1,(kMod*10+d)%k,e,o,(isTight)&&((s[index]-'0')==d),isLeading||d);
            }

            return dp[key]=ans;
        };

        return f(0,0,0,0,1,0);
    }
};