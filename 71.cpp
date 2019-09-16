#include <iostream>
#include <string>
#include <stack>

using namespace std;

string simplifyPath(string path) {
    stack<string> _stack;
    size_t i=0;
    while (i<path.size()){
        while (i<path.size()&&path[i]=='/') i++;
        string level="";
        while (i<path.size()&&path[i]!='/'){
            level+=path[i];
            i++;
        }
        if (level==".."&&!_stack.empty()) _stack.pop();
        else if (level=="."||level==".."||level=="") continue;
        else _stack.push(level);
    }
    
    if (_stack.empty()) return "/";
    string res="";
    while (!_stack.empty()){
        res="/"+_stack.top()+res;
        _stack.pop();
    }
    return res;
}

int main()
{
    string input;
    cin >> input;
    cout << simplifyPath(input);
    return 0;
}