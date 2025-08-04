class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans=1;
        map<int,int> map;
        int start=0,end=0,n=fruits.size();
        while(end<n){
            map[fruits[end]]++;
            if(map.size()>2){
                while(start<=end && map.size()>2){
                    map[fruits[start]]--;
                    if(map[fruits[start]]==0) map.erase(fruits[start]);
                    start++;
                }
            }
            else{
                ans=max(ans,end-start+1);
            }
            end++;
        }
        return ans;
    }
};