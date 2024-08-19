class Solution {
public:
    int vis[10000];
    int solve(vector<int>&a,int st,vector<int>&dp){
        if(st>=a.size()||st<0)return 0;
       
        if(vis[st])return 0;
        if(a[st]==0)return 1;
        if(dp[st]!=-1)return dp[st];

        int ind=a[st];
        int ans=0;
        vis[st]=1;
        ans=max(ans,solve(a,st-ind,dp));
        if(ans)return dp[st]=1;
        ans=max(ans,solve(a,st+ind,dp));
        if(ans)return dp[st]=1;
        
        

        return dp[st]=0;
    }
    bool canReach(vector<int>& arr, int start) {
        memset(vis,0,sizeof(vis));
        vector<int>dp(arr.size()+1,-1);
        return solve(arr,start,dp);
    }
};