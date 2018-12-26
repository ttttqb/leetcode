class Solution {
public:
    int ans=0;
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int len=height.size();
        vector<int> left(len,0),right(len,0);

        left[0]=height[0];
        for (int i=1;i<len;i++)
            left[i]=max(height[i],left[i-1]);
        right[len-1]=height[len-1];
        for (int i=len-2;i>=0;i--)
            right[i]=max(height[i],right[i+1]);
        for (int i=0;i<len;i++)
            ans+=min(right[i],left[i])-height[i];
        return ans;
    }
};