class Solution {
public:
    const int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        map<int,vector<pair<int,int>>>mp;
        for(auto i:roads){
            mp[i[0]].push_back({i[1],i[2]});
            mp[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        vector<int>ways(n,0);
        vector<long long>dist(n,LLONG_MAX);
        dist[0]=0;
        ways[0]=1;
        
       
        while(!pq.empty()){
            auto d=pq.top().first;
            auto node=pq.top().second;
            pq.pop();
            
            for(auto v:mp[node]){
                long long newdist=d+v.second;
                if(dist[v.first]>newdist){
                    dist[v.first]=newdist;
                    pq.push({newdist,v.first});
                    ways[v.first]=ways[node]%mod;
                }
                else if(dist[v.first]==newdist){
                    ways[v.first]=(ways[v.first]+ways[node])%mod;
                }
                
            }
        }

        return ways[n-1]%mod;

    }
};