class Solution {
public:
    bool isMatch(string s, string p) {
        int len1,len2;
        len1=s.size();
        len2=p.size();
        //bool **dp=new bool*[len1+1];
        //for (int i=0;i<len1+1;i++)
            //dp[i]=new bool[len2+1];傻逼leetcode，莫名其妙的过不了
        vector<vector<bool>> dp(len1+1);
        for (int i=0;i<len1+1;i++)
            dp[i].resize(len2+1);
        dp[0][0]=true;
        for (int i=1;i<=len2;i++)
            dp[0][i]=dp[0][i-1]&&(p[i-1]=='*');

        for (int i=1;i<=len1;i++)
            for (int j=1;j<=len2;j++){
                if (s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if (p[j-1]=='*')
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
            }
    
        //for (int i=1;i<=len1;i++){
          //  for(int j=1;j<=len2;j++)
            //    cout<<dp[i][j]<<" ";
            //cout<<endl;
       // }
        return dp[len1][len2];
    }
};