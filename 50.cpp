class Solution {
public:
    double myPow(double x, int n) {
        if (n<0) return 1/_pow(x,-n);
        return _pow(x,n);
    }
    double _pow(double x,int n){
        if (n==0) return 1;
        double hx=_pow(x,n/2);
        if (n%2==0) return hx*hx;
        else return hx*hx*x;
    }
};