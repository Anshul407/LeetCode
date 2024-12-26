class DSU{
    public:
    vector<int>parent,rank;
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int find(int u){
        if(u==parent[u])return u;
        return parent[u]=find(parent[u]);
    }
    void unionbyrank(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv)return ;
        if(rank[pu]>rank[pv])parent[pv]=pu;
        else if(rank[pu]<rank[pv])parent[pu]=pv;
        else {
            parent[pu]=pv;
            rank[pv]++;

        }
    }
};
class Solution {
public:

    static bool cmp(vector<int>&a,vector<int>&b){
        return a[0]>b[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU ua(n);
        DSU ub(n);
        sort(edges.begin(),edges.end(),cmp);
        int s=0;
        for(auto i:edges){
            int t=i[0];
            int x=i[1];
            int y=i[2];
            if(t==3){
                int pua=ua.find(x);
                int pva=ua.find(y);
                int pub=ub.find(x);
                int pvb=ub.find(y);
                if(pua!=pva||pub!=pvb){
                    s++;
                    ua.unionbyrank(x,y);
                    ub.unionbyrank(x,y);
                }
            }
            else if(t==1){
                int pu=ua.find(x);
                int pv=ua.find(y);
                if(pu!=pv){
                    ua.unionbyrank(x,y);
                    s++;
                }
            }else {
                int pu=ub.find(x);
                int pv=ub.find(y);
                if(pu!=pv){
                    ub.unionbyrank(x,y);
                    s++;
                }
            }
        }
        int cnta=0,cntb=0;
        for(int i=1;i<=n;i++){
            if(ua.find(i)==i)cnta++;
            if(ub.find(i)==i)cntb++;
        }
        if(cnta>1||cntb>1)return -1;
        return edges.size()-s;
    }


};