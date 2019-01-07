class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(n);
        for (int i=0;i<n;i++)
            f[i].resize(m);
        for (int i=0;i<m;i++)
            f[0][i]=1;
        for (int i=0;i<n;i++)
            f[i][0]=1;
        for (int i=1;i<n;i++)
            for (int j=1;j<m;j++)
                f[i][j]=f[i-1][j]+f[i][j-1];
        return f[n-1][m-1];
    }
};