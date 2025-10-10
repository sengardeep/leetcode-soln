class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        for(int i=n-1;i>=0;i--){
            int nxt=i+k;
            if(nxt<n) energy[i]+=energy[nxt];
        }
        int ans=*max_element(energy.begin(),energy.end());
        return ans;
    }
};