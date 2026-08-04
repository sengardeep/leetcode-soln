class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> stack;
        for(int i=0;i<nums.size();i++){
            while(!stack.empty() && nums[i]<0 && stack.top()>0 && stack.top()<abs(nums[i])){stack.pop();}
            if(nums[i]>0) stack.push(nums[i]);
            else{
                if(stack.empty() || stack.top()<0) stack.push(nums[i]);
                else if(stack.top()==abs(nums[i])) stack.pop();
            }
        }
        vector<int> ans;
        while(!stack.empty()){
            ans.push_back(stack.top());
            stack.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};