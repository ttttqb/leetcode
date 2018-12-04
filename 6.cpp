class Solution {
public:
    string ans;
    string convert(string s, int numRows) {
        vector<string> zs(numRows);
        int plen=(numRows-1)*2;
        vector<int> pos;
        if (numRows==1) return s;
        for (int i=0;i<numRows;i++) pos.push_back(i);
        for (int i=numRows;i<plen;i++) pos.push_back(plen-i);
        //for (int i=0;i<pos.size();i++) cout<<pos[i]<<" ";
        for (int i=0;i<s.size();i++) zs[pos[i%plen]].push_back(s[i]);
        for (int i=0;i<numRows;i++) ans+=zs[i];
        return ans;
    }
};