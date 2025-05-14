class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int,vector<pair<int,int>>>mp;
        for(auto i:times){
            mp[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,k});
        vector<int>ans(n+1,INT_MAX);
        ans[k]=0;
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            auto d=cur[0];
            auto i=cur[1];
            
            for(auto v:mp[i]){
                if(v.second+d<ans[v.first]){
                    ans[v.first]=v.second+d;
                    pq.push({v.second+d,v.first});
                }
            }
        }
        int maxi=INT_MIN;
        ans[0]=0;
        for(auto i:ans)maxi=max(i,maxi);
        return maxi==INT_MAX?-1:maxi;
    }
};