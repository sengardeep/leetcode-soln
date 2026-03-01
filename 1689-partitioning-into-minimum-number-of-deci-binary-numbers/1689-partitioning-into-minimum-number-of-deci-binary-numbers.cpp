class Solution {
public:
    int minPartitions(string n) {
        int ans=9;
        for(char c='9';c>='0';c--){
            if(n.find(c)!=string::npos){
                ans=(c-'0');
                break;
            }
        }
        return ans;
    }
};