class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        if(k>(n-k+1)) return 0;
        set<string> st;
        for(int i=0;i+k-1<n;i++){
            string temp=s.substr(i,k);
            st.insert(temp);
        }
        return (st.size()==(1<<k));
    }
};