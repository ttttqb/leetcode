class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(),ans=0;
        vector<int> f(n+1,0);
        for (int i=1;i<=n;i++){
            int j=i-2-f[i-1];
            if (s[i-1]=='(' || j<0 || s[j]==')') f[i]=0;
            else{
                f[i]=f[j]+f[i-1]+2;
                ans=max(ans,f[i]);
            }
        }
        return ans;
    }
};