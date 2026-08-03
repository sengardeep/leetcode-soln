class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=left;
        int i=0,diff=right-left;
        while((1<<i) <= diff){
            if((1<<i) > ans) return 0;
            if((ans&(1<<i))) ans^=(1<<i);
            i++;
        }
        for(int i=0;i<31;i++){
            int set=(right&(1<<i));
            if((ans&(1<<i)) && !set) ans^=(1<<i);
        }
        return ans;
    }
};