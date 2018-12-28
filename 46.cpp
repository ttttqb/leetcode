class Solution {
public:
    vector<vector<int>> ans;
    int len;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> now;
        len=nums.size();
        dfs(0,nums);
        return ans;
    }
    void dfs(int level, vector<int>& nums)
    {
        if (level==len) {
            ans.push_back(nums);
            return;
        }
        for (int i=level;i<len;i++){
            swap(nums[i],nums[level]);
            dfs(level+1,nums);
            swap(nums[i],nums[level]);
        }
    }
};