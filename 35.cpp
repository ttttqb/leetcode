class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid,left=0,right=nums.size()-1;
        if (nums.empty()) return 0;
        if (nums.size()==1) return (nums[0]>=target)?0:1;
        while (left<=right){
            mid=left+(right-left)/2;
            if (nums[mid]==target) return mid;
            if (mid>0 && nums[mid-1]<target && nums[mid]>target) return mid;
            if (nums[mid]>target) right=mid-1;
            else left=mid+1;
        }
        return (left==0)?0:nums.size();
    }
};