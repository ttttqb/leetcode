class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        if (len<3) return len;
        int len2=2;
        for (int i=2;i<len;i++){
            if (nums[i]!=nums[len2-2])
                nums[len2++]=nums[i];
        }
        return len2;
    }
};