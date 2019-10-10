class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size()==0) return;
        int p0,p1,p2;
        p0=-1;
        p1=0;
        p2=nums.size();
        while (p1<p2){
            if (nums[p1]==1) p1++;
            else if (nums[p1]==0){
                p0++;
                swap(nums[p0],nums[p1]);
                p1++;
            }else{
                p2--;
                swap(nums[p1],nums[p2]);
            }
        }
    }
};