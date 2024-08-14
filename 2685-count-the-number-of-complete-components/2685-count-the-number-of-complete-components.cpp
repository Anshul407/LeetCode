class Solution {
public:
    void dfs(int node,map<int,vector<int>>&mp,vector<bool>&vis,int &n,int &e){
        vis[node]=1;
        //adding node count
        n++;
        //adding edge size
        e+=mp[node].size();
        for(auto v:mp[node]){
            if(!vis[v]){
                dfs(v,mp,vis,n,e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        map<int,vector<int>>mp;
        for(auto i:edges){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
            
        }
        int ans=0;
        vector<bool>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int n=0,e=0;
                dfs(i,mp,vis,n,e);
                //e/2 because each edge counts 2 time
                //checking complete tree condition
                if(e/2==n*(n-1)/2)ans++;
            }
        }
        return ans;
    }
};