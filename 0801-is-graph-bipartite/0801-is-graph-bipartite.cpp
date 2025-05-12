class Solution {
public:
    int solve(int i,vector<vector<int>>&mp,vector<int>&vis,int cur){
        vis[i]=cur;
        for(auto v:mp[i]){
            if(vis[v]==cur)return 0;
            if(vis[v]==-1){
                vis[v]=!cur;
                if(!solve(v,mp,vis,!cur))return 0;
            }
        }return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int>vis(graph.size(),-1);
        return solve(0,graph,vis,0);
    }
};