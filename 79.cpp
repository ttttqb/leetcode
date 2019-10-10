class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++){
                vis[i][j]=true;
                if (dfs(board, vis, word, i, j, 0)) return true;
                vis[i][j]=false;
            }
        return false;
    }
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, string word, int x, int y, int index){
        int m=board.size();
        int n=board[0].size();
        int dx[4]={-1,1,0,0};int dy[4]={0,0,-1,1};
        
        if (index==word.size()-1) return word[index]==board[x][y];
        if (word[index]!=board[x][y]) return false;
        bool res=false;
        vis[x][y]=true;
        for (int i=0;i<4;i++){
            int _x=x+dx[i],_y=y+dy[i];
            if (_x<0 || _y<0 || _x>=m || _y>=n || vis[_x][_y]) continue;
            if (dfs(board, vis, word, _x, _y, index+1)) return true;
        }
        vis[x][y]=false;
        return res;
    }
};