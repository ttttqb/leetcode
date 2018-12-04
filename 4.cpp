class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m,n;
        m = nums1.size(); n = nums2.size();

        if (m > n)
        {
            nums1.swap(nums2);
            int tint = m;
            m=n; n=tint;
        }
        if (m==0){
            if (n%2) return (double)nums2[n/2];
            else return (nums2[n/2-1]+nums2[n/2])/2.0;
        }
        int l=0, r=m;
        int mid1, mid2;
        while (l<=r)
        {
            //cout << l << " " << r << endl;
            int i=(l+r)>>1;
            int j=((m+n+1)>>1)-i;
            //cout<<i<<" "<<j<<endl;
            if (i<r && nums1[i]<nums2[j-1]) l=i+1;
            else if (i>l && nums1[i-1]>nums2[j]) r=i-1;
            else{
                if (i==0) mid1=nums2[j-1];
                else if (j==0) mid1=nums1[i-1];
                else mid1=max(nums1[i-1],nums2[j-1]);
                if ((m+n)%2) return mid1;
                if (i==m) mid2=nums2[j];
                else if (j==n) mid2=nums1[i];
                else mid2=min(nums1[i],nums2[j]);
                if ((m+n)%2) return (double)max(mid1,mid2);
                else return (mid1+mid2)/2.0;
            }
        }
    }
};