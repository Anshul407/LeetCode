class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>mp,int u,vector<int>&vis,int p){
        
        vis[u]=p;
        for(auto v:mp[u]){
            if(vis[v]==vis[u])return false;
            if(vis[v]==-1){
            vis[v]=1-p;
            int newcol=1-p;
            if(!dfs(mp,v,vis,newcol))return false;}

            
        }

        return true;



    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<graph.size();i++){
            for(auto it:graph[i]){
                mp[i].push_back(it);
            }
        }
        vector<int>vis(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(vis[i]==-1){
               if( !dfs(mp,i,vis,1))return false;
            }
        }
        return 1;
        
    }
};