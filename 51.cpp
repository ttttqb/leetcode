class Solution {
public:
    vector<vector<string>> ans;
    int nn;
    vector<vector<string>> solveNQueens(int n) {
        vector<int> queens(n,-1);
        nn=n;
        dfs(queens,0);
        return ans;
    }
    void dfs(vector<int>& queens, int row)
    {
        if (row==nn){
            vector<string> now(nn, string(nn,'.'));
            for (int i=0;i<nn;i++)
                now[i][queens[i]]='Q';
            ans.push_back(now);
        } else{
            for (int i=0;i<nn;i++){
                if (check(queens, row, i)){
                    queens[row]=i;
                    dfs(queens, row+1);
                    queens[row]=-1;
                }
            }
        }
    }
    bool check(vector<int>& queens, int row, int col){
        for (int i=0;i<row;i++)
            if (queens[i]==col || abs(row-i)==abs(col-queens[i]))
                return false;
        return true;
    }
};