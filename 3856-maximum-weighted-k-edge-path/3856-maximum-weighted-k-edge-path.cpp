class Solution {
public:
    vector<unordered_map<int,unordered_map<int,int>>>dp;
    int solve(int i,map<int,vector<pair<int,int>>>&mp,int k,int t){
        if(t<=0)return -1e6;
        if(k<0)return -1e6;
        if(k==0){return 0;}
        if(mp[i].empty())return -1e6;
        if(dp[i].count(k)&&dp[i][k].count(t))return dp[i][k][t];
        int ans=-1e6;
        for(auto &x:mp[i]){
            if(t-x.second<=0)continue;
            auto cur=solve(x.first,mp,k-1,t-x.second);
            if(cur!=-1e6)
            ans=max(ans,x.second+solve(x.first,mp,k-1,t-x.second));

        }
        return dp[i][k][t]=ans;
    }
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        if(edges.size()<k)return -1;
        dp.resize(n+1);
        map<int,vector<pair<int,int>>>mp;
        for(auto i:edges){
            mp[i[0]].push_back({i[1],i[2]});  
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            ans=max(ans,solve(i,mp,k,t));
        }
        return ans;
    }
};