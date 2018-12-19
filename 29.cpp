class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a,b,ans;
        long long m,c;
        a=abs((long long)dividend);
        b=abs((long long)divisor);
        if (a<b) return 0;
        ans=0;
        while (a>=b){
            m=b;
            c=1;
            while (a>(m<<1)){
                m<<=1;
                c<<=1;
            }
            ans+=c;
            a-=m;
        }
        //if (ans>INT_MAX) ans=INT_MAX;
        if ((dividend<0)^(divisor<0)) ans=-ans;
        if (ans>INT_MAX) ans=INT_MAX;
        return ans;
    }
};