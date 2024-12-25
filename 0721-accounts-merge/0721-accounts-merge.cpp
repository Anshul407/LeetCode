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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        abc(accounts.size());
        map<string,int>mp;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                auto s=accounts[i][j];
                if(mp.find(s)!=mp.end()){
                    unionbyrank(mp[s],i);
                }else mp[s]=i;
            }
        }
        map<int,vector<string>>mp2;
        for(auto v:mp){
            auto x=v.first;
            auto p=v.second;
            auto curp=findp(p);
            mp2[curp].push_back(x);
        }
        vector<vector<string>>ans;

        for(auto x:mp2){
            auto n=x.first;
            auto w=accounts[n][0];
            auto arr=x.second;
            sort(arr.begin(),arr.end());
            vector<string>temp;
            temp.push_back(w);
            temp.insert(temp.end(),arr.begin(),arr.end());
            ans.push_back(temp);
            
        }
        return ans;


    }
};