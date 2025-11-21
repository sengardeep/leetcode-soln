class Solution {
public:
    int pivotInteger(int n) {
        int sum=n*(n+1)/2;
        int start=1,end=n;
        while(start<=end){
            int mid=(start+end)/2;
            int s=(mid*(mid+1))/2;
            int rem=sum-s+mid;
            if(s==rem) return mid;
            if(s<rem) start=mid+1;
            else end=mid-1;
        }
        return -1;
    }
};