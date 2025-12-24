class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=accumulate(begin(apple),end(apple),0);
        int ans=0;
        sort(begin(capacity),end(capacity));
        reverse(begin(capacity),end(capacity));
        int i=0;
        while(sum>0){
            if(sum>=capacity[i]){
                ans++;
                sum-=capacity[i];
            }else{
                sum=0;
                ans++;
                break;
            }
            i++;
        }
        return ans;
    }
};