class Solution {
public:
    bool checkValidString(string s) {
        int extra=0;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(s[i]);
            else if(s[i]==')'){
                if(!st.empty()) st.pop();
                else if(extra) extra--;
                else return 0;
            }
            else extra++;
        }
        if(st.empty()) return 1;
        extra=0;
        while(!st.empty()) st.pop();
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='}') st.push(s[i]);
            else if(s[i]=='('){
                if(!st.empty()) st.pop();
                else if(extra) extra--;
                else return 0;
            }
            else extra++;
        }
        return st.empty();
    }
};