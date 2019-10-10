class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1==s2) return true;
        if (s1.size()!=s2.size()) return false;
        if (s1.size()==1) return false;
        
        int n=s1.size();
        vector<int> vis(26,0);
        for (int i=0;i<n;i++){
            vis[s1[i]-'a']++;
            vis[s2[i]-'a']--;
        }
        for (int i=0;i<26;i++)
            if (vis[i]) return false;
        
        bool res;
        for (int mid=1;mid<n;mid++){
            res=isScramble(s1.substr(0,mid), s2.substr(0,mid)) && 
                isScramble(s1.substr(mid,n-mid),s2.substr(mid,n-mid));
            if (res) return true;
            //if (mid==n-mid)
            res=isScramble(s1.substr(0,mid), s2.substr(n-mid)) &&
                isScramble(s1.substr(mid),s2.substr(0,n-mid));
            if (res) return true;
        }
        return false;
    }
};