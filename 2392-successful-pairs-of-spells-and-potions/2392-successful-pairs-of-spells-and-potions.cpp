class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m=potions.size(),n=spells.size();
        vector<int> pairs(n,0);
        sort(begin(potions),end(potions));
        for(int i=0;i<n;i++){
            long long num = (success-1)/spells[i];
            int idx = upper_bound(begin(potions),end(potions),num)-potions.begin();
            pairs[i]=(m-idx);
        }
        return pairs;
    }
};