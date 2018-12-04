class Solution {
public:
    string ans;
    string intToRoman(int num) {
        vector<int> value{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbol{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        ans="";
        for (int i=0;i<value.size();i++){
            while (num>=value[i]){
                num-=value[i];
                ans+=symbol[i];
            }
        }
        return ans;
    }
};