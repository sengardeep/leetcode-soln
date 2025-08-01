class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            vector<int> curr(i);
            curr[0]=curr[i-1]=1;
            if(i>2){
                vector<int> prev=ans[i-2];
                for(int j=1;j<i-1;j++){
                    curr[j]=prev[j-1]+prev[j];
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};