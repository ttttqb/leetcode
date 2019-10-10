class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> _stack;
        heights.push_back(0);//放个0保证都能出栈
        int len=heights.size();
        int maxarea=0;
        for (int i=0;i<len;i++){
            if (_stack.empty()||heights[_stack.top()]<heights[i]) _stack.push(i);
            else{
                while (!_stack.empty()&&heights[_stack.top()]>=heights[i]){
                    int index=_stack.top();
                    _stack.pop();
                    int length=(_stack.empty())?i:(i-_stack.top()-1);
                    maxarea=max(maxarea, heights[index]*length);
                }
                _stack.push(i);
            }
        }
        return maxarea;
    }
};