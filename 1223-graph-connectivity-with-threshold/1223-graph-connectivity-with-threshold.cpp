class Solution {
public:
    bool fact(int i,int j,int k){
        int mini=min(i,j);
        if(mini<k)return 0;
        for(int x=k+1;x<=mini;x++){
            if(i%x==0&&j%x==0)return 1;
        }
        return 0;
    }
    vector<int>rank,parent;
    void abc(int n){
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
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        abc(n);
        for (int i=threshold+1;i<=n;i++) {
            for(int j=2*i;j<=n;j+=i) {
                unionbyrank(i,j);
            }
        }
        vector<bool>ans;
        for(auto i:queries){
            if(findp(i[0])==findp(i[1]))ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;

    }
};