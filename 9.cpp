

class Solution {
public:
    bool isPalindrome(int x) {
        string s;
        int l,r;
        s=to_string(x);
        l=0;r=s.size()-1;
        while (l<r) if (s[l++]!=s[r--]) return false;
        return true;
    }
};