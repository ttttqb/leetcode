class Solution {
public:
    string countAndSay(int n) {
        string ans="1",now;
        int t;
        if (n<=0) return "";
        while (--n){
            now="";
            for (int i=0;i<ans.size();i++){
                t=1;
                for (;i+1<ans.size()&&ans[i]==ans[i+1];i++,t++);
                string s=to_string(t);
                now+=s+ans[i];
            }
            ans=now;
        }
        return ans;
    }
};