#include <regex>
class Solution {
public:
    bool isNumber(string s) {
        string ss=R"(^\s*[-+]?(?:\d+|\d+\.\d*|\d*\.\d+)(?:e[+-]?\d+)?\s*$)";
        
        regex pattern(ss);
        smatch result;
        return regex_match(s, result, pattern);
    }
};