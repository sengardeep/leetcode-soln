class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        for(int i=0;i<points.size()-1;i++){
            int x1=points[i][0],x2=points[i+1][0];
            int y1=points[i][1],y2=points[i+1][1];
            ans+=max(abs(y1-y2),abs(x1-x2));
        }
        return ans;
    }
};