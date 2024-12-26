class Solution {
public:
    int s;
    static bool cmp(vector<int>a,vector<int>b){
        return a[2]<b[2];
    }
    class DSU {
        public:
    vector<int>rank,parent;
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findp(int node){
        if(node==parent[node])return node;
        return parent[node]=findp(parent[node]);
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
    }};
    int kruskal(vector<vector<int>>&egdes,int skip,int force,int n){
        DSU uf(n);
        int ans=0;
        if(force!=-1){
            int u=egdes[force][0];
            int v=egdes[force][1];
            int w=egdes[force][2];
          
            uf.unionbyrank(u,v);
            ans+=w;
        }
        for(int i=0;i<egdes.size();i++){
            if(i==skip)continue;
            int u=egdes[i][0];
            int v=egdes[i][1];
            int w=egdes[i][2];
            if(uf.findp(u)==uf.findp(v))continue;
            else uf.unionbyrank(u,v);
            ans+=w;
        }
        for(int i = 0; i < n; i++) {
            if(uf.findp(i) != uf.findp(0))
                return INT_MAX;
        }
        return ans;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
      
        for(int i=0;i<edges.size();i++)
        {
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),cmp);

        int mstwt=kruskal(edges,-1,-1,n);
        vector<vector<int>>ans(2);
        for(int i=0;i<edges.size();i++){
            int curwt=kruskal(edges,i,-1,n);
            if(curwt>mstwt){
                ans[0].push_back(edges[i][3]);
            }else if (kruskal(edges,-1,i,n)==mstwt) ans[1].push_back(edges[i][3]);
        }
        return ans;
    }
};