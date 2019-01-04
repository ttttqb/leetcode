class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (string s: strs){
            vector<int> v(26,0);
            string ss;
            for (char c: s)
                v[c-'a']++;
            for (int x: v)
                ss+=to_string(x)+"#";
            m[ss].push_back(s);
        }
        for (auto vs: m)
            ans.push_back(vs.second);
        return ans;
    }
};