class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans,now;
        ans=INT_MIN;now=0;
        for (int x:nums){
            now=max(x,now+x);
            ans=max(ans,now);
        }
        return ans;
    }
};