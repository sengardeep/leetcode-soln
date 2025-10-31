class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size()-2;
        int sum=accumulate(nums.begin(),nums.end(),0)-n*(n-1)/2;
        int squareSum=0;
        for(int i=0;i<nums.size();i++) squareSum+=(nums[i]*nums[i]);
        squareSum-=n*(n-1)*(2*n-1)/6;
        // cout<<squareSum<<endl;
        // cout<<sum<<endl;
        int pro=(sum*sum-squareSum)/2;
        int D=sum*sum-4*pro;
        // cout<<D<<endl;
        if(D>=0)
        {
        int x1=(sum+sqrt(D))/2;
        int x2=(sum-sqrt(D))/2;
        return {x1,x2};
        }
        return {};
    }
};