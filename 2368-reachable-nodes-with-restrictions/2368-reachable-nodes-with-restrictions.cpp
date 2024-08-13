class Solution {
public:
    void dfs(int node,map<int,vector<int>>&mp,vector<bool>&vis){
        vis[node]=1;
        for(auto i:mp[node]){
            if(!vis[i]){
                dfs(i,mp,vis);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<bool>vis(n,0);
        map<int,vector<int>>mp;
        for(auto i:edges){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
       for(auto i:restricted){
          vis[i]=1;
       }
       dfs(0,mp,vis);
       int ans=0;
       for(auto i:vis){
        if(i==1)ans++;
       }
       return ans-restricted.size();

    }
};