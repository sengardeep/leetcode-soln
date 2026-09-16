class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int sum=0;
        for(int i=0;i<n;i++) 
        {
            gas[i]-=cost[i];
            sum+=gas[i];
        }
        if(sum<0) return -1;
        sum=0;
        for(int i=0;i<n;i++){
            if(gas[i]>=0){
                sum=gas[i];
                int j=(i+1)%n;
                while(sum>=0 && j!=i){
                    sum+=gas[j];
                    j=(j+1)%n;
                }
                if(j==i) return i;
                else if(j<i) return -1;
                i=j-2;
            }
        }
        return -1;
    }
};