class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        set<int> set;
        for(auto x : bulbs) {
            if(set.count(x)) set.erase(set.find(x));
            else set.insert(x);
        }
        vector<int> ans;
        for(auto x : set) ans.push_back(x);
        return ans;
    }
};