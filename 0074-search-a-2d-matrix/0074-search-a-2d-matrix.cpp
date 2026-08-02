class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int r=0,start=0,end=m-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(matrix[mid][0]==target) return 1;
            else if(matrix[mid][0] < target){
                r=mid;
                start=mid+1;
            }
            else end=mid-1;
        }
        start=0,end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(matrix[r][mid]==target) return 1;
            else if(matrix[r][mid] < target) start=mid+1;
            else end=mid-1;
        }
        return 0;
    }
};