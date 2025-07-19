class Solution {
public:
    int maxi;
    // long long solve(int node,vector<bool>&on,long long k,long long curcost,long long curans){
    //     if(curcost>k||on[node]==0)return -1e6;
    //     if(node==on.size()-1)return curans;
    //     long long ans=INT_MIN;
    //     for(auto &v:mp[node]){
    //         long long cur=solve(v.first,on,k,curcost+v.second,min(curans,v.second));
    //         ans=max(ans,cur);
    //     }return ans;
        
    // }
    long long bfs(int node,vector<bool>&on,long long k, unordered_map<int,vector<pair<int,long long>>>&mp){
        queue<pair<int,pair<long long,int>>>q;
        q.push({node,{0,INT_MAX}});
        unordered_map<int,unordered_map<int,long long>>dp;
        int ans=-1;
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            auto nd=cur.first;  
            auto curcost=cur.second.first;
            auto mainans=cur.second.second;
            if(curcost>k)continue; 
            if(nd==on.size()-1){
                ans=max(ans,mainans);
                continue;
            }
            if(ans==maxi)return ans;
            if(mainans<=ans)continue;
            if(dp[nd].find(mainans)!=dp[nd].end()&&dp[nd][mainans]<=curcost)continue;
            dp[nd][mainans]=curcost;
            for(auto &v:mp[nd]){
                if(curcost+v.second<=k)
                q.push({v.first,{curcost+v.second,min(mainans,(int)v.second)}});
            }
        }return ans;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        unordered_map<int,vector<pair<int,long long>>>mp;
        maxi=INT_MIN;
        for(auto &i:edges){
            if(online[i[0]]==0||online[i[1]]==0)continue;
            mp[i[0]].push_back({i[1],i[2]});
            maxi=max(maxi,i[2]);
        }
        auto ans=bfs(0,online,k,mp);
        if(ans==INT_MAX||ans==INT_MIN||ans<0)return -1;
        return ans;
    }
};