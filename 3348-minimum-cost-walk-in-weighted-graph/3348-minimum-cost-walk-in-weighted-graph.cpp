class Solution {
public:
    vector<int>cost;
    vector<int> parent;
    int find(int x) {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }
    void unionbyrank(int x, int y) {
        parent[y] = x;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        cost.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++){parent[i]=i;cost[i]=-1;}
        for(auto v:edges){
            int u=v[0];
            int x=v[1];
            int w=v[2];
            int p1=find(u);
            int p2=find(x);
            if(p1!=p2){
            unionbyrank(p1,p2);
            cost[p1]&=cost[p2];
            }
            cost[p1]&=w;

        }
        vector<int>ans;
        for(auto i:query){
            int u=i[0];
            int v=i[1];
            if(u==v)ans.push_back(0);
            else if(find(u)!=find(v))ans.push_back(-1);
            else {
                int p=find(u);
                ans.push_back(cost[p]);
            }
        }
        return ans;
    }
};