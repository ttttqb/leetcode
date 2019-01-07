class Solution {
public:
    int climbStairs(int n) {
        vector<int> f(n+1);
        f[1]=1;f[2]=2;
        //if (n<=2) return f[n];
        for (int i=3;i<=n;i++)
            f[i]=f[i-1]+f[i-2];
        return f[n];
    }
};