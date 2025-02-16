class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> p;
        for(auto it : amount) p.push(it);
        int ans=0;
        while(true)
        {
            int first=p.top();
            p.pop();
            int second=p.top();
            p.pop();
            if(first > 0) first--;
            else break;
            if(second > 0) second--; 
            ans++;
            p.push(first);
            p.push(second);
        }
        return ans;
    }
};