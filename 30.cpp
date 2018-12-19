class Solution {
public:
    vector<int> ans;
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty()||words.empty()) return {};
        unordered_map<string,int> _words, v;
        for (auto w:words) _words[w]++;
        
        int wordsLen=words[0].size(); 
        if (wordsLen>s.size()) return {};
        int left,count;
        for (int i=0; i<wordsLen; i++){
            left=i;
            count=0;
            v.clear();
            for (int j=i;j<=s.size()-wordsLen;j+=wordsLen){
                string ss=s.substr(j, wordsLen);
                if (_words.count(ss)){
                    v[ss]++;
                    if (v[ss]<=_words[ss])
                        count++;
                    else{
                        while (v[ss]>_words[ss]){
                            string frontWord=s.substr(left, wordsLen);
                            v[frontWord]--;
                            if (v[frontWord]<_words[frontWord]) count--;
                            left+=wordsLen;
                        }
                    }
                    
                    if (count==words.size()){
                        ans.push_back(left);
                        v[s.substr(left,wordsLen)]--;
                        count--;
                        left+=wordsLen;
                    }
                } else{
                    v.clear();
                    count=0;
                    left=j+wordsLen;
                }
            }
        }
        return ans;
    }
};