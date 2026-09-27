class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                string temp="";
                while(!st.empty() && st.top()!='('){
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                for(auto x : temp)
                st.push(x);
            } else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};