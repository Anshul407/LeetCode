class Solution {
public:
    vector<int>parent,rank;
    void abc(int n){
        parent.resize(n+1);
        rank.resize(n+1,1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int find(int cur){
        if(parent[cur]==cur)return cur;
        return parent[cur]=find(parent[cur]);
    }
    void unionbyrank(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv)return ;

        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }else{
            parent[pv]=pu;
        }
        if(rank[pu]==rank[pv])rank[pu]++;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            abc(1001);
            for(auto i:edges){
                auto u=i[0];
                auto v=i[1];
                auto pu=find(u);
                auto pv=find(v);
                if(pu==pv)return {u,v};
                unionbyrank(u,v);
            }return {-1,-1};
    }
};