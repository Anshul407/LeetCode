class Solution {
public:
    int solve(int i,vector<vector<int>>&mp,vector<int>&vis,int cur){
        vis[i]=cur;
        for(auto v:mp[i]){
            if(vis[v]==cur)return 0;
            if(vis[v]==-1){
                if(!solve(v,mp,vis,!cur))return 0;
            }
        }return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>vis(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(vis[i]==-1){
                if(!solve(i,graph,vis,0))return 0;
            }
        }
        return 1;
    }
};