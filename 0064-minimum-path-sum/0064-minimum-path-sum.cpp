class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i==n-1&&j==m-1){
            return grid[i][j];
        }
        if(i>=n&&j>=m){
            return 1e9+7;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int left=INT_MAX;
        int right=INT_MAX;
        if(i<n-1){
            int up=i+1;
            left=solve(grid,up,j,n,m,dp);
        }
        if(j<m-1){
            int up=j+1;
            right=solve(grid,i,up,n,m,dp);
        }

        return dp[i][j]=min(right,left)+grid[i][j];

    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        int i=0,j=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return solve(grid,i,j,n,m,dp);
        
    }
};