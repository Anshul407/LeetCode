class DSU{
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
    }
};
class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DSU uf(n);
        vector<bool>ans;
        
        for(auto i:requests){
            auto u=i[0];
            auto v=i[1];
            DSU temp=uf;
            temp.unionbyrank(u,v);
            bool flag=true;
            for(auto x:restrictions){
                if(temp.findp(x[0])==temp.findp(x[1])){
                    flag=false;
                    break;
                }
            }
            ans.push_back(flag);
            if(flag){
                uf.unionbyrank(u,v);
            }
        }
        return ans;
    }
};