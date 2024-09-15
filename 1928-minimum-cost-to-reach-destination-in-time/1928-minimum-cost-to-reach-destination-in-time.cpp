class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& pf) {
        int n = pf.size();
        vector<vector<pair<int, int>>> mp(n);
        
        for (auto& e : edges) {
            mp[e[0]].push_back({e[1], e[2]});
            mp[e[1]].push_back({e[0], e[2]});
        }
        
        vector<int> cost(n, INT_MAX);
        vector<int> time(n, INT_MAX);
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        cost[0] = pf[0];
        time[0] = 0;
        pq.push({pf[0], 0, 0});
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int wt = it[0];
            int t = it[1];
            int node = it[2];
            
            for (auto& v : mp[node]) {
                int nxt = v.first;
                int trv = v.second;
                int nt = t + trv;
                int nw = wt + pf[nxt];
                
                if (nt <= maxTime) {
                    if (nw < cost[nxt]) {
                        cost[nxt] = nw;
                        time[nxt] = nt;
                        pq.push({nw, nt, nxt});
                    } 
                    else if (nt < time[nxt]) {
                        time[nxt] = nt;
                        pq.push({nw, nt, nxt});
                    }
                }
            }
        }
        
        return cost[n-1] == INT_MAX ? -1 : cost[n-1];
    }
};
