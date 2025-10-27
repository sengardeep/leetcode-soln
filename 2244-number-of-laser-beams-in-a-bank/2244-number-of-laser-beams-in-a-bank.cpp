class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        int prev=0;
        for(int i=0;i<bank.size();i++){
            int one=count(begin(bank[i]),end(bank[i]),'1');
            if(one!=0){
                ans+=prev*one;
                prev=one;
            }
        }
        return ans;
    }
};