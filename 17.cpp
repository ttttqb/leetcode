class Solution {
public:
    array<string,10> dict={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        dfs(digits,0,"");
        return ans;
    }
    void dfs(string digits, int level, string now){
        if (level==digits.size()) {
            ans.push_back(now);
            return;
        }
        string i2n=dict[digits[level]-'0'];
        for (int i=0;i<i2n.size();i++)
            dfs(digits, level+1, now+string(1,i2n[i]));
    }
};