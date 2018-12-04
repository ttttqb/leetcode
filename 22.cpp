class Solution {
public:
    int len;
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        len=n;
        search("",0,0);
        return ans;
    }
    void search(string now, int l, int r){
        if (l+r==len*2){
            ans.push_back(now);
            return;
        }
        if (l<len) search(now+'(',l+1,r);
        if (r<l) search(now+')',l,r+1);
    }
};