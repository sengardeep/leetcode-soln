class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nsl(n,-1),nsr(n,n);
        //left
        stack<int> stack;
        for(int i=0;i<n;i++){
            while(!stack.empty() && heights[stack.top()]>=heights[i]) stack.pop();
            if(!stack.empty()) nsl[i]=stack.top();
            stack.push(i);
        }
        while(!stack.empty()) stack.pop();
        //right
        for(int i=n-1;i>=0;i--){
            while(!stack.empty() && heights[stack.top()]>=heights[i]) stack.pop();
            if(!stack.empty()) nsr[i]=stack.top();
            stack.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int h=heights[i],w=nsr[i]-nsl[i]-1;
            ans=max(ans,h*w);
        }
        return ans;
    }
};