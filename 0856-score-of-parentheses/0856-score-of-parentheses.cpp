class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string> st;
        for(char c : s){
            if(c=='(') st.push("(");
            else{
                int res = 0;
                while(st.top()!="(") {
                    string top = st.top();
                    st.pop();
                    int curr = stoi(top);
                    res += curr;
                }
                res *= 2;
                if(!res) res=1;
                st.pop();
                st.push(to_string(res));
            }
        }
        int ans=0;
        while(!st.empty()){
            ans += stoi(st.top());
            st.pop();
        }
        return ans;
    }
};