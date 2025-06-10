class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int,vector<int>>mp;
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1){
                mp[manager[i]].push_back(i);
                mp[i].push_back(manager[i]);
            }
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({informTime[headID],headID});
        vector<int>res(n,INT_MAX);
        res[headID]=informTime[headID];
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            int wt=cur[0];
            int node=cur[1];
            if(wt>res[node])continue;
            for(auto v:mp[node]){
                if(informTime[v]+wt<res[v]){
                    res[v]=informTime[v]+wt;
                    pq.push({res[v],v});
                }
            }
        }
        int maxi=0;
        for(auto i:res)
        {
            if(i!=INT_MAX)maxi=max(maxi,i);
        }
        
        return maxi;
    }
};