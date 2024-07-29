class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i>=n)return 0;
        if(i==n-1)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        
        for(int x=0;x<m;x++){
            if(j==x)continue;
            int xx=grid[i][j]+solve(grid,i+1,x,n,m,dp);
            ans=min(xx,ans);
        
        }
        return dp[i][j]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            ans=min(ans,solve(grid,0,i,n,m,dp));
        }
        return ans;
    }
};