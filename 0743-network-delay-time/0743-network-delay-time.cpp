class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto i:times){
            mp[i[0]].push_back({i[1],i[2]});
        }
        vector<int>res(n+1,1e9);
        res[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int dist=it.first;
            int node=it.second;
            for(auto v:mp[node]){
                if(dist+v.second<res[v.first]){
                    res[v.first]=v.second+dist;
                    pq.push({res[v.first],v.first});
                }
            }
        }
        int ans=INT_MIN;
    
        for(int i=1;i<=n;i++){
            if(res[i]==1e9)return -1;
            ans=max(ans,res[i]);
        }

        if(ans==0)return -1;
        return ans;
    }
};