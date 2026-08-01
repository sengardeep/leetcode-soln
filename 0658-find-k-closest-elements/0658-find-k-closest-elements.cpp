class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int index=0,mn=1e9;
        for(int i=k;i<n;i++){
            int nxt=abs(arr[i]-x),prev=abs(arr[i-k]-x);
            if(prev>nxt){
                index=i-k+1;
                continue;
            }
        }
        vector<int> ans;
        for(int i=index;i<index+k;i++) ans.push_back(arr[i]);
        return ans;
    }
};