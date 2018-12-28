class Solution {
public:
    int jump(vector<int>& nums) {
        int ans, now, maxd;
        if (nums.empty()||nums.size()==1) return 0;
        ans=now=maxd=0;
        for (int i=0;i<nums.size()-1;i++)
        {
            maxd=max(maxd,i+nums[i]);
            if (now==i) ans++,now=maxd;
        }
        return ans;
    }
};