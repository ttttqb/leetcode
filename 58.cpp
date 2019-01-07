class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;;
        if (s.empty()) return 0;
        auto c=s.end()-1;
        while (*c==' ' && c>=s.begin()) c--;
        if (c==s.begin() && *c==' ') return 0;
        while (*c!=' ' && c>=s.begin()) {
            c--;
            ans++;
        }
        return ans;
    }
};