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
    bool similar(string &x,string &y){
        int cnt=0;
        for(int i=0;i<x.size();i++){
            if(x[i]!=y[i])cnt++;
        }
        return cnt==2||cnt==0;
    }

    int numSimilarGroups(vector<string>& strs) {
        abc(strs.size());
        for(int i=0;i<strs.size();i++){
            for(int j=i+1;j<strs.size();j++){
                auto w=strs[i];
                auto x=strs[j];
                if(similar(w,x)){
                    unionbyrank(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<strs.size();i++){
            if(findp(i)==i)ans++;
        }
        return ans;
    }
};