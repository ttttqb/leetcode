#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minDistance(string word1, string word2) {
    int m=word1.length(),n=word2.length();
    // int **f=new int*[m+1];
    // for (int i=0;i<m+1;i++)
    //     f[i]=new int[n+1];
        vector<vector<int>> f(2,vector<int>(n+1));
    
    //for (int i=1;i<=m;i++) f[i][0]=i;
    for (int i=1;i<=n;i++) f[0][i]=i;
    for (int i=1;i<=m;i++){
        f[i&1][0]=i;
        for (int j=1;j<=n;j++)
        {
            if (word1[i-1]==word2[j-1]) f[i&1][j]=f[i-1&1][j-1];
            else f[i&1][j]=min(f[i-1&1][j]+1, min(f[i-1&1][j-1]+1, f[i&1][j-1]+1));
        }      
    }

    return f[m&1][n];  
}

int main()
{
    string a,b;
    cin >> a>>b;
    cout << minDistance(a,b);
    return 0;
}