class Solution {
public:
    vector<int> ans;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m,n;
        m=matrix.size();n=matrix[0].size();
        int up,down,left,right;
        up=0;down=m-1;left=0;right=n-1;
        while (1){
            for (int i=left;i<=right;i++)
                ans.push_back(matrix[up][i]);
            up++;
            if (up>down) break;
            
            for (int i=up;i<=down;i++)
                ans.push_back(matrix[i][right]);
            right--;
            if (right<left) break;
            
            for (int i=right;i>=left;i--)
                ans.push_back(matrix[down][i]);
            down--;
            if (up>down) break;
            
            for (int i=down;i>=up;i--)
                ans.push_back(matrix[i][left]);
            left++;
            if (right<left) break;
        }
        return ans;
    }
};