class Solution {
public:
    bool dfs(int i,map<int,vector<int>>&mp,int p,int a,int b,vector<int>&vis){
        vis[i]=1;
        for(auto v:mp[i]){
            if(v==p)continue;
            if(vis[v])return 1;
            if(dfs(v,mp,i,a,b,vis))return 1;
        }
        return 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int,vector<int>>mp;
        for(auto i:edges){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
            int u=i[0];
            int v=i[1];
            vector<int>vis(edges.size()+1,0);
            if(dfs(u,mp,-1,u,v,vis)){
                return {u,v};
            }
        }
        return {};
    }
};