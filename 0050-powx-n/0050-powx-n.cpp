class Solution {
public:
    double calcPow(double x, int n){
        if(n==0) return 1.0;
        if(n==1) return x;
        double half = calcPow(x,n/2);
        return (n%2==0)? half*half : half*half*x;
    }
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        if(n==1) return x;
        if(n<0) return (1/calcPow(x,n));
        return calcPow(x,n);
    }
};