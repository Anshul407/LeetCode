class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        map<int,vector<pair<int,double>>>mp;
        int j=0;
        for(auto i:edges){
            mp[i[0]].push_back({i[1],succProb[j]});
            mp[i[1]].push_back({i[0],succProb[j]});
            j++;  
        }

        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start_node});
        vector<double>res(n,0.0);
        res[start_node]=0;
        while(!pq.empty()){
            auto wt=pq.top().first;
            auto node=pq.top().second;
            pq.pop();
            if(node==end_node)return wt;
            for(auto v:mp[node]){
                auto cn=v.first;
                auto cw=v.second;
                if(cw*wt>res[cn]){
                    res[cn]=cw*wt;
                    pq.push({cw*wt,cn});
                }
            }
        }
        return 0.0;
    }
};