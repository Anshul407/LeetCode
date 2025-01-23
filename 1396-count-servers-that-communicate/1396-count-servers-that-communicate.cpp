class Solution {
public:
    vector<int>rank,parent;
    void abc(int n){
        rank.resize(n+1,1);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int find(int cur){
        if(parent[cur]==cur)return cur;

        return parent[cur]=find(parent[cur]);
    }
    void unionbyrank(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb)return ;

        if(rank[pa]>rank[pb]){
            parent[pb]=pa;
        }else if(rank[pa]<rank[pb]){
            parent[pa]=pb;
        }else{
            parent[pb]=pa;
            rank[pa]++;
        }
        
    }
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size()+grid[0].size();
        abc(n+1);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int u=i;
                    int v=j+grid.size();
                    unionbyrank(u,v);
                }
            }
        }
        int ans=0;
        map<int,int>mp;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    mp[find(i)]++;
                }
            }
        }
        for(auto i:mp){
            if(i.second>1)ans+=i.second;
        }return ans;    
    }
};