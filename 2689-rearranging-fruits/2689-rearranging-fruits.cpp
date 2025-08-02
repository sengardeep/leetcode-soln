class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int> map;
        for(int i : basket1) map[i]++;
        for(int i : basket2) map[i]--;
        for(auto it : map) if((abs(it.second))%2) return -1;

        vector<int> v;
        for(auto [el,freq] :  map) 
        {
            int n = abs(freq)/2;
            for(int i=0;i<n;i++) v.push_back(el);
        }

        long long ans=0;
        int mini=min(*min_element(basket1.begin(),basket1.end()),*min_element(basket2.begin(),basket2.end()));

        int m=v.size();
        nth_element(v.begin(),v.begin()+m/2,v.end());
        m/=2;
        for(int i=0;i<m;i++) 
        {
        ans+=min(v[i],2*mini);
        }
        return ans;
    }
};