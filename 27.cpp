class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j,len;
        len=nums.size();
        if (!len) return 0;
        j=0;
        for (int i=0;i<len;i++){
            if (nums[i]!=val) nums[j++]=nums[i];
        }
        return j;
    }
};