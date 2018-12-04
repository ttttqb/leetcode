class Solution {
public:
    vector<vector<int>> ans;
    vector<int> abc;
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l,r;
        sort(nums.begin(),nums.end());
        if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
        for (int i=0;i<nums.size();i++){
            if (nums[i]>0) break;
            if (i>0 && nums[i]==nums[i-1]) continue;
            l=i+1;r=nums.size()-1;
            while (l<r){
                if (nums[l]+nums[r]==-nums[i]){
                    abc.clear();
                    abc.push_back(nums[i]);
                    abc.push_back(nums[l]);
                    abc.push_back(nums[r]);
                    ans.push_back(abc);
                    while (l<r && nums[l]==nums[l+1]) l++;
                    while (l<r && nums[r]==nums[r-1]) r--;
                    l++;r--;
                } else if (nums[l]+nums[r]<-nums[i]) l++;
                else r--;
            }
        }
        return ans;
    }
};