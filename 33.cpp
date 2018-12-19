class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left,right,mid;
        left=0;right=nums.size()-1;
        while (left<=right){
            mid=left+((right-left)>>1);
            if (nums[mid]==target) return mid;
            if (nums[mid]<nums[right]){
                if (nums[mid]<target && nums[right]>=target) left=mid+1;
                else right=mid-1;
            }else{
                if (nums[mid]>target && nums[left]<=target) right=mid-1;
                else left=mid+1;
            }
        }
        return -1;
    }
};