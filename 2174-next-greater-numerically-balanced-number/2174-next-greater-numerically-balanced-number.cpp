class Solution {
public:
    int nextBeautifulNumber(int n) {
        for(int i=n+1;i<=1224444;i++){
            if(isBalanced(i)) return i;
        }
        return 0;
    }
private:
    bool isBalanced(int n){
        map<int,int> mp;
        while(n){
            mp[n%10]++;
            n/=10;
        }
        for(auto [num,f] : mp) if(num!=f) return 0;
        return 1;
    }
};