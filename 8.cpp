class Solution {
public:
    int myAtoi(string str) {
        int i=0,l,ans,c;
        int flag=0;
        int len=str.size();
        int numlen=0;
        string num;
        
        while (i<len) {
            if (str[i]!=' ') break;
            i++;
        }
        if (i==len) return 0;
        if (str[i]=='+') flag=1;
        else if (str[i]=='-') flag=-1;
        else if (str[i]<'0'||str[i]>'9') return 0;
        
        if (flag){
            int j=i+1;
            if (j==len) return 0;
            if (str[j]<'0'||str[j]>'9') return 0;
            i=j;
        } else flag=1;
        
        l=i;
        while (i<len){
            if (str[i]<'0'||str[i]>'9') break;
            numlen++;i++;
        }
        num=str.substr(l,numlen);
        ans=0;i=0;c=0;
        while (i<num.size()){
            c=num[i++]-'0';
            if (flag==1 && (ans>INT_MAX/10 || ans>(INT_MAX-c)/10 )) return INT_MAX;
            if (flag==-1 && (-ans<INT_MIN/10 || -ans<(INT_MIN+c)/10)) return INT_MIN;
            ans=ans*10+c;
        }
        return (flag==1)?ans:-ans;
    }
};