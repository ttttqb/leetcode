class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m,n;
        n=obstacleGrid.size();
        m=obstacleGrid[0].size();
        vector<vector<int>> f(n);
        for (int i=0;i<n;i++)
            f[i].resize(m);
        
        bool flag=true;
        for (int i=0;i<m;i++){
            if (flag && !obstacleGrid[0][i])
                f[0][i]=1;
            else
                f[0][i]=0,flag=false;
        }
        
        flag=true;
        for (int i=0;i<n;i++){
            if (flag && !obstacleGrid[i][0])
                f[i][0]=1;
            else
                f[i][0]=0,flag=false;
        }
        for (int i=1;i<n;i++)
            for (int j=1;j<m;j++){
                if (!obstacleGrid[i][j])
                    f[i][j]=f[i-1][j]+f[i][j-1];
                else
                    f[i][j]=0;
            }
        
       /* for (int i=0;i<n;i++,cout<<endl)
            for (int j=0;j<m;j++){
                cout<<f[i][j]<<" ";
            }*/
        return f[n-1][m-1];
    }
};