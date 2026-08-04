class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stack;
        for(auto s : operations){
            if(s=="C"){
                stack.pop();
            }else if(s=="D"){
                stack.push(stack.top()*2);
            }else if(s=="+"){
                int x=stack.top();
                stack.pop();
                int sum=x+stack.top();
                stack.push(x);
                stack.push(sum);
            }else{
                int num = stoi(s);
                stack.push(num);
            }
        }
        int ans=0;
        while(!stack.empty()){
            ans+=stack.top();
            stack.pop();
        }
        return ans;
    }
};