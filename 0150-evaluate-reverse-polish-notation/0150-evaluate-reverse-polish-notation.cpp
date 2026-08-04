class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for(auto s : tokens){
            if(s=="+"){
                int first = stack.top();
                stack.pop();
                int second = stack.top();
                stack.pop();
                stack.push(second+first);
            }else if(s=="-"){
                int first = stack.top();
                stack.pop();
                int second = stack.top();
                stack.pop();
                stack.push(second-first);
            }else if(s=="*"){
                int first = stack.top();
                stack.pop();
                int second = stack.top();
                stack.pop();
                stack.push(second*first);
            }else if(s=="/"){
                int first = stack.top();
                stack.pop();
                int second = stack.top();
                stack.pop();
                stack.push(second/first);

            }else{
                stack.push(stoi(s));
            }
        }
        return stack.top();
    }
};