class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i,j,c,s;
        i=a.size()-1;j=b.size()-1;
        c=0;
        while (i>=0 || j>=0){
            s=c;
            if (i>=0) s+=a[i--]-'0';
            if (j>=0) s+=b[j--]-'0';
            ans+=to_string(s%2);
            c=s/2;
        }
        reverse(ans.begin(),ans.end());
        return (c)?"1"+ans:ans;
    }
};