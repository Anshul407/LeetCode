class Solution {
public:
    vector<int>rank,parent;
    void DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int findpar(int node){
        if(node==parent[node])return node;
        
        return parent[node]=findpar(parent[node]);
        
    }
    void unionbyrank(int u,int v){
        int pu=findpar(u);
        int pv=findpar(v);
        if(pu==pv)return ;
        int ru=rank[pu];
        int rv=rank[pv];
        
        if(ru<rv){
            parent[pu]=pv;
        }else if(ru>rv){
            parent[pv]=pu;
        }else{
            parent[pu]=pv;
            rank[pv]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        DSU(points.size());
        vector<vector<int>>v;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                if(i!=j){
                    v.push_back({abs(points[i][0]- points[j][0])+abs(points[i][1]-points[j][1]),i,j});
                }
            }
        }
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<v.size();i++){
            int u=v[i][1];
            int vv=v[i][2];
            int w=v[i][0];

            if(findpar(u)==findpar(vv))continue;
            unionbyrank(u,vv);
            ans+=w;
        }
        return ans;
    }
};