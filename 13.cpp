class Solution {
public:
    int romanToInt(string s) {
        int ans=0,temp;
        unordered_map<char, int> s2v{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i=0;i<s.size();i++){
            temp=s2v[s[i]];
            if (i==s.size()-1 || s2v[s[i+1]]<=temp) ans+=temp;
            else ans-=temp;
        }
        return ans;
    }
};