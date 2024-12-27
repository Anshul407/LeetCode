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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        abc(s.size());
        for(auto i:pairs){
            unionbyrank(i[0],i[1]);
        }
        unordered_map<int, priority_queue<char>>mp;

        for(int i=0;i<s.size();i++){
           mp[findp(i)].push(s[i]);
        }
        
        for(int i=s.size()-1;i>=0;i--){
             auto p=findp(i);
             s[i]=mp[p].top();
             mp[p].pop();
        }
        return s;
    }
};