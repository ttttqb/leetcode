class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n);
        for (int i=0;i<n;i++) ans[i].resize(n);
        int up,down,left,right,now;
        up=left=0;down=right=n-1;
        now=1;
        while (1){
            for (int i=left;i<=right;i++) ans[up][i]=now++;
            if (++up>down) break;
            
            for (int i=up;i<=down;i++) ans[i][right]=now++;
            if (--right<left) break;
            
            for (int i=right;i>=left;i--) ans[down][i]=now++;
            if (up>--down) break;
            
            for (int i=down;i>=up;i--) ans[i][left]=now++;
            if (right<++left) break;
        }
        return ans;
    }
};