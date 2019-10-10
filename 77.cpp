class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(n,1,k,temp,ans);
        return ans;
    }
    void dfs(int n, int head, int k, vector<int>& temp, vector<vector<int>>& ans){
        if (k==0){
            ans.push_back(temp);
            return;
        }
        for (int i=head;i<=n;i++){
            temp.push_back(i);
            dfs(n,i+1,k-1,temp,ans);
            temp.pop_back();
        }
    }
};