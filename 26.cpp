class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i,j,l;
        l=nums.size();
        j=0;
        if (!l) return 0;
        for (int i=0;i<l;i++){
            if (nums[i]!=nums[j])
                nums[++j]=nums[i];
        }
        return j+1;
    }
};