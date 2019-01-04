class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size()-1;
        int beg=n;
        for(int i=n;i>=0;i--){
            if (i+nums[i]>=beg)
                beg=i;
        }
        return beg==0;
    }
};