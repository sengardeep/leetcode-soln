class Solution {
public:
    string reorganizeString(string s) {
        if(s.size()<=1) return s;
        vector<int> mp(26,0);
        for(auto c : s) mp[c-'a']++;
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<26;i++) if(mp[i]) pq.push({mp[i],'a'+i});
        string ans="";
        while(pq.size()>1){
            auto [f1,ch1] = pq.top();
            pq.pop();
            auto [f2,ch2] = pq.top();
            pq.pop();
            ans+=ch1;
            ans+=ch2;
            f1--;
            f2--;
            if(f1) pq.push({f1,ch1});
            if(f2) pq.push({f2,ch2});
        }
        if(pq.empty()) return ans;
        if(pq.top().first>1 || pq.top().second==ans.back()) return "";
        ans+=pq.top().second;
        return ans;
    }
};