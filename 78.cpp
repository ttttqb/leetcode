class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(0,nums.size(),nums,temp,ans);
        return ans;
    }
    void dfs(int head, int n, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        if (head==n) {
            ans.push_back(temp);
            return;
        }
        dfs(head+1, n, nums, temp, ans);
        temp.push_back(nums[head]);
        dfs(head+1, n, nums, temp, ans);
        temp.pop_back();
    }
};