class Solution {
public:
    vector<int>parent,rank;
    void abc(int n){
        parent.resize(n+1);
        rank.resize(n+1,1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int findp(int n){
        if(n==parent[n])return n;
        return parent[n]=findp(parent[n]);
    }
    void unionbyrank(int u,int v){
        int pu=findp(u);
        int pv=findp(v);
        if(pu==pv)return ;

        if(rank[pu]>rank[pv])parent[pv]=pu;
        else if(rank[pu]<rank[pv])parent[pu]=pv;
        else {
            parent[pu]=pv;
            rank[pv]++;

        }
    }
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        abc(n+m+1);
         map<int,int>mp;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int u=i;
                    int v=j+n;
                    unionbyrank(u,v);
                    
                }
            }
        }
     
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    mp[findp(i)]++;
                }
            }
        }
        for(auto i:mp){
            if(i.second>1)ans+=i.second;
        }
        return ans;
        
    }
};