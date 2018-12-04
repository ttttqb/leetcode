class Solution {
public:
    int reverse(int x) {
        int ans=0;
        int c;
        while (x!=0){
            c=x%10;
            x/=10;
            if (ans>INT_MAX/10 || ans<INT_MIN/10 || abs(ans)>(INT_MAX-abs(c))/10) return 0;
            ans=ans*10+c;
        }
        return ans;
    }
};