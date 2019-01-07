class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> now,ans;
        int width,space,slot;
        width=0;
        for (string w:words){
            if (width+w.size()>maxWidth){
                string line;
                space=now.size()+maxWidth-width;
                if (now.size()==1){
                    line.append(now[0]);
                    line.append(space,' ');
                }else{
                    slot=space/(now.size()-1);
                    if (space % (now.size()-1) !=0) slot++;
                    for (int i=0;i<now.size()-1;i++){
                        slot=space/(now.size()-1-i);
                        if (space % (now.size()-1-i) !=0) slot++;
                        line.append(now[i]);
                        line.append(slot,' ');
                        space-=slot;
                    }
                    line.append(now[now.size()-1]);
                    line.append(maxWidth-line.size(),' ');
                }
                ans.push_back(line);
                now.clear();
                width=w.size()+1;
                now.push_back(w);
            } else{
                now.push_back(w);
                width+=w.size()+1;
            }
        }
        if (now.empty()) return ans;
        else{
            string line;
            space=now.size()+maxWidth-width;
            if (now.size()==1){
                line.append(now[0]);
                line.append(space,' ');
            }else{
                for (int i=0;i<now.size()-1;i++){
                    line.append(now[i]);
                    line.append(" ");
                }
                line.append(now[now.size()-1]);
                line.append(maxWidth-line.size(),' ');
            }
            ans.push_back(line);
            return ans;
        }
    }
};