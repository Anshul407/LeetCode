class Solution {
public: 
    void dfs(int i,map<int,vector<pair<int,int>>>&mp,vector<bool>&vis,int &ans){
        vis[i]=1;
        for(auto v:mp[i]){
            if(!vis[v.first]){
                ans=min(ans,v.second);
                dfs(v.first,mp,vis,ans);
            }
        
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        map<int,vector<pair<int,int>>>mp;
        for(auto i:roads){
            mp[i[0]].push_back({i[1],i[2]});
            mp[i[1]].push_back({i[0],i[2]});
        }
        int ans=INT_MAX;
        vector<bool>vis(n,0);
        dfs(1,mp,vis,ans);
        return ans;
    }
};