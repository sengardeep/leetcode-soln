class Solution {
public:
    int minimumDeletions(string s) {
       string lis="";
       for(auto c : s){
        auto ub=upper_bound(begin(lis),end(lis),c)-begin(lis);
        if(ub==lis.size()) lis+=c;
        else lis[ub]=c;
       } 
       int n=s.size(),m=lis.size();
       return n-m;
    }
};