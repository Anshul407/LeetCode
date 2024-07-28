class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i==n-1&&j==m-1)return 1;
        if(i>=n||j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        int down=0,right=0;
        if(i<n-1){
            int forw=i+1;
            if(grid[forw][j]!=1){
                grid[forw][j]=1;
                down=solve(grid,forw,j,n,m,dp);
                grid[forw][j]=0;
            }

        }
        if(j<m-1){
            int forw=j+1;
            if(grid[i][forw]!=1){
                grid[i][forw]=1;
                right=solve(grid,i,forw,n,m,dp);
                grid[i][forw]=0;
            }
        }

        return dp[i][j]=right+down;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int i=0,j=0,n=Grid.size(),m=Grid[0].size();
        if(Grid[i][j]==1)return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(Grid,i,j,n,m,dp);
    }
};