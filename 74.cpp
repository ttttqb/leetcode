class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if (!m) return false;
        int n=matrix[0].size();
        if (!n) return false;
        
        int line=-1;
        for (int i=0;i<m;i++){
            if (matrix[i][n-1]>=target){
                line=i;
                break;
            }
        }
        
        if (line==-1) return false;
        for (int j=0;j<n;j++){
            if (matrix[line][j]==target)
                return true;
        }
        return false;
    }
};