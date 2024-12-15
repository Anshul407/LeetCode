class Solution {
public:
    unordered_map<int,vector<int>>mp,mp2;
    map<pair<int,int>,int>dp;
    int solve(int i,int p){
        if(dp.find({i,p})!=dp.end())return dp[{i,p}];
        int ans=0;
        for(auto v:mp[i]){
            if(v!=p){
                
                ans+=solve(v,i);
            }
        }
        for(auto v:mp2[i]){
            if(v!=p){
                ans++;
                ans+=solve(v,i);
            }
        }
        return dp[{i,p}]=ans;
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        dp.clear();
        mp.clear();
        mp2.clear();
        for(auto i:edges){
            mp[i[0]].push_back(i[1]);
            mp2[i[1]].push_back(i[0]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
        ans.push_back(solve(i,-1));}
        return ans;
    }
};