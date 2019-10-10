/*
滑动窗口，注意移动时候count要根据字符够不够用的情况进行增减
*/

class Solution {
public:
    string minWindow(string s, string t) {
	int l, r;
	l = r = 0;
	int minLen, minL, minR;
	minLen = 0x7f7f7f7f;

	int count = 0;
	unordered_map<char, int> tMap;
	for (int i = 0; i < t.size(); i++)
		tMap[t[i]]++;

	for (; r < s.size(); r++) {
		if (tMap.find(s[r]) != tMap.end())
			if (tMap[s[r]]-- > 0) count++;
		while (count == t.size()) {
			if (r - l < minLen) {
				minLen = r - l;
				minL = l;
				minR = r;
			}
			if (tMap.find(s[l]) != tMap.end())
				if (++tMap[s[l]] > 0) count--;
			l++;
		}
	}
	return (minLen == 0x7f7f7f7f) ? "" : s.substr(minL, minR - minL + 1);
}
};