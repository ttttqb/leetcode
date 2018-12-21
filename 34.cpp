class Solution {
public:
    vector<int> ans;
    vector<int> searchRange(vector<int>& nums, int target) {
        int beg,end;
        beg=end=-1;
        ans.push_back(beg);
        ans.push_back(end);
        int left,right,mid;
        left=0;right=nums.size()-1;
        if (nums.empty()) return ans;
        if (nums[0]>target||nums[right]<target) return ans;
        while (left<=right){
            mid=left+(right-left)/2;
            if (nums[mid]==target) {
                int i;
                for (i=mid;nums[i]==target&&i>=0;i--);
                beg=i+1;
                for (i=mid;nums[i]==target&&i<nums.size();i++)
                end=i;
                ans.clear();
                ans.push_back(beg);
                ans.push_back(end);
                return ans;
            }
            if (nums[mid]<target) left=mid+1;
            else right=mid-1;
        }
        return ans;
    }
};