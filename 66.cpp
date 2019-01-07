class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size();
        for (int i=len-1;i>=0;i--){
            if (digits[i]<9){
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }
        vector<int> ans(len+1,0);
        ans[0]=1;
        return ans;
    }
};