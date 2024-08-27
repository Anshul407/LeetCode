class Solution {
public:
  
   
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        map<int, vector<pair<int, double>>> mp;
        for (int j = 0; j < edges.size(); ++j) {
            mp[edges[j][0]].emplace_back(edges[j][1], succProb[j]);
            mp[edges[j][1]].emplace_back(edges[j][0], succProb[j]);
        }

        priority_queue<pair<double,int>,vector<pair<double,int>>>q;
        vector<double>ans(n,0.0);

        q.push({0,start_node});
        vector<bool>vis(n,0);
        vis[start_node]=1;
        while(!q.empty()){
            auto node=q.top().second;
            auto p=q.top().first;
            q.pop();
            if(p==0)p=1;
            if(node==end_node)return p;
            for(auto v:mp[node]){
                if(p*v.first>ans[v.second]&&!vis[v.second]){
                    vis[v.second]=1;
                    v.second=p*v.first;
                    q.push({p*v.first,v.second});
                }
            }
        }
        
        return 0.0;
    }
};
