class Solution {
public:
    string ans;
    int max_len;
    string longestPalindrome(string s) {
        int len=s.size();
        max_len=0;
        
        if (len<=1) return s;
        for (int i=0;i<len;i++){
            int l,r;
            l=i;r=i;
            while (l>=0 && r<len){
                if (s[l]==s[r]){
                    if (r-l+1>max_len){
                        max_len=r-l+1;
                        ans=s.substr(l,r-l+1);
                    }
                    l--;r++;
                } else break;
            }
        }
        for (int i=0;i<len;i++){
            int l,r;
            l=i;r=i+1;
            while (l>=0 && r<len){
                if (s[l]==s[r]){
                    if (r-l+1>max_len){
                        max_len=r-l+1;
                        ans=s.substr(l,r-l+1);
                    }
                    l--;r++;
                } else break;
            }
        }
        return ans;
    }
};