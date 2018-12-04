class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum=nums[0]+nums[1]+nums[2];
        int diff=abs(sum-target);
        int l,r,now,dnow;
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size()-2;i++){
            l=i+1;r=nums.size()-1;
            while (l<r){
                now=nums[i]+nums[l]+nums[r];
                dnow=abs(now-target);
                if (diff>dnow){
                    diff=dnow;
                    sum=now;
                }
                if (now<target) l++;
                else r--;
            }
        }
        return sum;
    }
};