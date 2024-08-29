class Solution {
public:
  int n;
    void dfs( vector<vector<int>>&stones,int v, vector<bool>&vis){
        vis[v]=1;
        

        for(int i=0;i<n;i++){
            
            if (!vis[i] && (stones[i][0] == stones[v][0] || stones[i][1] == stones[v][1])) {
                dfs(stones, i, vis);
            }
        }

       
    }
    int removeStones(vector<vector<int>>& stones) {
        
        
       
        n=stones.size();
        int count = 0;
        vector<bool>vis(stones.size(),0);
        for(int i = 0; i<stones.size(); i++) {
            if(vis[i])
                continue;
            dfs(stones, i, vis);
            count++;
        }
        return n-count;
    }
};