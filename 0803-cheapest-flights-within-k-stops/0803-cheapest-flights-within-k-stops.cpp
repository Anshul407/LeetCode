class Solution {
public:
    int dp[101][105];
    vector<int>vis;
    int solve(int i,int j,map<int,vector<pair<int,int>>>&mp,int k){
        if(k<-1)return 1e6;
        if(i==j)return 0;
        if(dp[i][k+1]!=-1)return dp[i][k+1];
       
        int ans=1e6;
        for(auto v:mp[i]){
            if(vis[v.first]==0)
            {
                auto cur=solve(v.first,j,mp,k-1);
                ans=min(ans,v.second+cur);
            }
        }
        
        return dp[i][k+1]= ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        memset(dp,-1,sizeof(dp));
        vis.resize(n+1,0);
        map<int,vector<pair<int,int>>>mp;
        for(auto i:flights){
            mp[i[0]].push_back({i[1],i[2]});
        }
        auto ans= solve(src,dst,mp,k);
        if(ans==1e6)return -1;
        return ans;
    }
};