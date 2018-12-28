class Solution {
public:
    vector<vector<int>> ans;
    int len;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
        bool flag;
        for (int i=level;i<len;i++)
        {
            flag=true;
            for (int j=level;j<i;j++)
                if (nums[i]==nums[j]) {
                    flag=false;
                    break;
                }
            if (flag){
                swap(nums[i],nums[level]);
                dfs(level+1,nums);
                swap(nums[i],nums[level]);
            }
        }
    }
};