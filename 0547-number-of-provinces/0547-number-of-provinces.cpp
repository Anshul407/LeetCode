class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&mp,int u,vector<int>&vis){
        if(vis[u])return ;
        vis[u]=true;
        for(auto v:mp[u]){
            if(!vis[v]){
                dfs(mp,v,vis);
            }
        }
    }
    void bfs(unordered_map<int,vector<int>>&mp,int u,vector<int>&vis){
        queue<int>q;
        q.push(u);
        vis[u]=true;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(auto v:mp[it]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]){
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        int V=mp.size();
        int ans=0;
        vector<int>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bfs(mp,i,vis);
                ans++;
            }
        }
        return ans;
    }
};