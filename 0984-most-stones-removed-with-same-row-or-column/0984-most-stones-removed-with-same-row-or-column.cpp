class Solution {
public:
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
    int removeStones(vector<vector<int>>& stones) {
        int n=0,m=0;
        for(auto i:stones){
            n=max(n,i[0]);
            m=max(m,i[1]);
        }
        abc(n+m+1);
        map<int,int>mp;
        for(auto i:stones){
            int u=i[0];
            int v=i[1]+n+1;
            unionbyrank(u,v);
            mp[u]=1;
            mp[v]=1;
        }
        int cnt=0;
        for(auto v:mp){
            if(findp(v.first)==v.first)cnt++;
        }
        return stones.size()-cnt;
    }
};