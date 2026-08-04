class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(auto c : s){
            if(c=='(' || c=='[' || c=='{') stack.push(c);
            else{
                if(stack.empty()) return 0;
                if((c==')' && stack.top()!='(')||(c==']' && stack.top()!='[')||(c=='}'&&stack.top()!='{')) return 0;
                stack.pop();
            }
        }
        return stack.empty();
    }
};