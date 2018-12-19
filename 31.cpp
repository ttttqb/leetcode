class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int>::iterator i,j,k;
        for (i=nums.end()-1;i!=nums.begin();){
            j=i--;
            if (!(*i<*j)) continue;
            for (k=nums.end();!(*i<*(--k)););
            iter_swap(i,k);
            reverse(j,nums.end());
            return;
        }
        reverse(nums.begin(),nums.end());
        return;
    }
};