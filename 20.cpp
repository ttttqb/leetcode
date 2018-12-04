class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        for (int i=0;i<s.size();i++){
            switch (s[i]){
                case '(':case '{':case '[':
                    sk.push(s[i]);
                    break;
                case ')':
                    if (sk.empty()||sk.top()!='(') return false;
                    sk.pop();
                    break;
                case '}':
                    if (sk.empty()||sk.top()!='{') return false;
                    sk.pop();
                    break;
                case ']':
                    if (sk.empty()||sk.top()!='[') return false;
                    sk.pop();
                    break;
                default:
                    return false;
            }
        }
        return sk.empty();
    }
};