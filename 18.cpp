class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        int l,r,now;
        if (nums.empty() || nums.size()<4) return {};
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size()-3;i++){
            for (int j=i+1;j<nums.size()-2;j++){
                if (j>i+1 && nums[j]==nums[j-1]) continue;
                l=j+1;r=nums.size()-1;
                while (l<r){
                    now=nums[i]+nums[j]+nums[l]+nums[r];
                    if (now==target){
                        vector<int> ans_now{nums[i],nums[j],nums[l],nums[r]};
                        ans.insert(ans_now);
                        l++,r--;
                    } else if (now<target) l++;
                    else r--;
                }
            }
        }
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};