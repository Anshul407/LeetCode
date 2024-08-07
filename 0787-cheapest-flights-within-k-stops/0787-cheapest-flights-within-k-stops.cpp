class Solution {
public:
    using int2 = pair<int, int>;
    using int3 = tuple<int, int, int>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<vector<int2>> adj(n);
        for(auto& f: flights){
            int s=f[0], e=f[1], w=f[2];
            adj[s].emplace_back(w, e); 
        }
        vector<int> dist(n, 1e9);
        priority_queue<int3,  vector<int3>, greater<int3>> pq;
        dist[src] = 0;
        pq.emplace(0, 0, src);
        while (!pq.empty()) {
            auto [stop, d, i] = pq.top();
        //    cout<<"d="<<d<<", i="<<i<<" ,stop="<<stop<<endl;
            pq.pop();
            if (stop>k) //when stop>k not taken
                continue;
            int d2;
            for (const auto& [w, j] : adj[i]) {
                d2 = d + w;
                if (d2 < dist[j]) {
                    dist[j] = d2;
                    pq.emplace(stop+(j!=dst), d2, j);
                }
            }
        }
        return dist[dst]>=1e9?-1:dist[dst];
    }
};

