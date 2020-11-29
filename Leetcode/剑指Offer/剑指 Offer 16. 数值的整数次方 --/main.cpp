class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        //考虑到负数右移永远是负数，
        if(n==-1) return 1/x;
        if(n&1) return myPow(x*x, n>>1)*x;
        else return myPow(x*x, n>>1);
    }
};
