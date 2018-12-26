class Solution {
public:
    set<vector<int>> ans;
    vector<int> now;
    int len;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        if (candidates.empty() || candidates[0]>target) return {};
        len=candidates.size();
        dfs(candidates,0,target,now);
        
        vector<vector<int>> _ans(ans.begin(),ans.end());
        return _ans;
    }
    
    void dfs(vector<int>& a, int index, int target,vector<int>& now)
    {
        if (target==0) {
            ans.insert(now);
            return;
        }
        if (target<0 || index>=len || a[index]>target) return;
        for (int i=index;i<len;i++){
            now.push_back(a[i]);
            dfs(a, i+1, target-a[i], now);
            now.pop_back();
        }
        return;
    }
};