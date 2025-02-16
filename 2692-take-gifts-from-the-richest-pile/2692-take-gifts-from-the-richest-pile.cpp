class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> p;
        for(auto it : gifts)
        p.push(it);

        while(k--)
        {
            int top=p.top();
            p.pop();
            p.push(floor(sqrt(top)));
        }

        long long ans=0;
        while(!p.empty()) 
        {
            ans+=p.top();
            p.pop();
        }

        return ans;
    }
};