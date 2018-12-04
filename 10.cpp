class Solution {
public:
    string _substr(string s,int pos){
        if (pos<s.size()) return s.substr(pos);
        return string("");
    }
    bool isMatch(string s, string p) {
        cout<<s<<" "<<p<<endl;
        int len_s=s.size();
        int len_p=p.size();
        if (!len_s && !len_p) return true;
        if (len_s==1 && s[0]=='\"') return isMatch("",p);
        if (len_s && !len_p) return false;
        //cout<<len_s<<" "<<len_p<<endl;
        if (len_p>1 && p[1]=='*'){
            if (len_s==0) return isMatch(s,_substr(p,2));
            if (s[0]==p[0] || p[0]=='.')
                return isMatch(_substr(s,1),p) || isMatch(s,_substr(p,2));
            else return isMatch(s,_substr(p,2));
        }
        if (len_s && (s[0]==p[0] || p[0]=='.')) 
            return isMatch(_substr(s,1),_substr(p,1));
        return false;
    }
};