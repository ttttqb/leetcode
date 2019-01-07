/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        int newStart,newEnd;
        bool flag=true;
        newStart=newInterval.start;newEnd=newInterval.end;
        for (auto i=intervals.begin();i!=intervals.end();i++){
            if (i->end<newInterval.start || i->start>newInterval.end){
                //if (!flag) ans.push_back(Interval(newStart,newEnd));
                ans.push_back(*i);
            }
            else{
                newStart=min(newStart, i->start);
                newEnd=max(newEnd, i->end);
                flag=false;
            }
        }
        if (flag) ans.push_back(newInterval);
        else ans.push_back(Interval(newStart,newEnd));
        sort(ans.begin(),ans.end(),[](Interval& a, Interval& b){return a.start<b.start;});
        return ans;
    }
};