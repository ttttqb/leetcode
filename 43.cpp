class Solution {
public:
    string multiply(string num1, string num2) {
        string ans;
        int n1,n2;
        n1=num1.size();
        n2=num2.size();
        vector<int> mul(n1+n2,0);
        for (int i=0;i<n1;i++)
            for (int j=0;j<n2;j++)
                mul[n1+n2-2-i-j]+=(num1[i]-'0')*(num2[j]-'0');
        int c=0;
        for (int i=0;i<n1+n2;i++){
            mul[i]+=c;
            c=mul[i]/10;
            mul[i]%=10;
        }
        c=n1+n2-1;
        while (mul[--c]==0);
        if (c<0) return "0";
        while (c>=0) ans.push_back(mul[c--]+'0');
        return ans;
    }
};