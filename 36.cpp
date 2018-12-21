class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty()) return true;
        bool row[9],col[9];
        for (int i=0;i<9;i++){
            memset(row,0,sizeof(row));
            memset(col,0,sizeof(col));
            for (int j=0;j<9;j++){
                if (board[i][j]!='.'){
                    if (row[board[i][j]-'1']) return false;
                    row[board[i][j]-'1']=true;
                }
                if (board[j][i]!='.'){
                    if (col[board[j][i]-'1']) return false;
                    col[board[j][i]-'1']=true;
                }
            }
        }
        bool subbox[9];
        int dx[9]={-1,0,1,-1,0,1,-1,0,1};
        int dy[9]={-1,-1,-1,0,0,0,1,1,1};
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++){
                memset(subbox,0,sizeof(subbox));
                for (int k=0;k<9;k++){
                    int _i,_j;
                    _i=i*3+dx[k]+1;
                    _j=j*3+dy[k]+1;
                    if (board[_i][_j]!='.'){
                        if (subbox[board[_i][_j]-'1']) return false;
                        subbox[board[_i][_j]-'1']=true;
                    }
                }
            }
        return true;
    }
};