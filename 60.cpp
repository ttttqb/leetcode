class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<int> factor(n);
        string v="123456789";
        factor[0]=1;
        for (int i=1;i<n;i++)
            factor[i]=factor[i-1]*i;
        k--;
        for (int i=n;i>=1;i--){
            int c=k/factor[i-1];
            k%=factor[i-1];
            ans.push_back(v[c]);
            v.erase(c,1);
        }
        return ans;
    }
};