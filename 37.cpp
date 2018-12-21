class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board,0,0);
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j){
        if (i==9) return true;
        if (j==9) return dfs(board,i+1,0);
        if (board[i][j]=='.'){
            for (int k=0;k<9;k++){
                board[i][j]=(char)k+'1';
                if (check(board,i,j)) 
                    if (dfs(board,i,j+1)) return true;
                board[i][j]='.';
            }
        } else return dfs(board,i,j+1);
        return false;
    }
    
    bool check(vector<vector<char>>& board, int x, int y){
        for (int i=0;i<9;i++){
            if (i!=x && board[x][y]==board[i][y]) return false;
            if (i!=y && board[x][y]==board[x][i]) return false;
        }
        int dx=x/3*3,dy=y/3*3;
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                if ((i+dx!=x || j+dy!=y) && board[i+dx][j+dy]==board[x][y]) return false;
        return true;
    }
};