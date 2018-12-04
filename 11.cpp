class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret=-1,l=0,r=height.size()-1;
        while (l<r){
            ret=max(ret,min(height[l],height[r])*(r-l));
            if (height[l]>height[r]) r--;
            else l++;
        }
        return ret;
    }
};