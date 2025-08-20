class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int> map;
        int ans=1;
        for(int i=0;i<arr.size();i++){
            // map[arr[i]]=1;
            map[arr[i]]=map[arr[i]-difference]+1;
            ans=max(ans,map[arr[i]]);
        }
        return ans;
    }
};