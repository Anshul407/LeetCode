class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,int n,int m,int cur,vector<vector<int>>&dp){
        
        if(dp[i][j]!=-1)return dp[i][j];

        int l=0,mm=0,nn=0;
        if(i>0&&j<m-1&&grid[i-1][j+1]>grid[i][j]){
           
            l=1+solve(grid,i-1,j+1,n,m,grid[i-1][j+1],dp);
            
        }
        if(j<m-1&&grid[i][j+1]>grid[i][j]){
           
            mm=1+solve(grid,i,j+1,n,m,grid[i][j+1],dp);
            
        }
        if(i<n-1&&j<m-1&&grid[i+1][j+1]>grid[i][j]){
           
            nn=1+solve(grid,i+1,j+1,n,m,grid[i+1][j+1],dp);
             
        }

        return dp[i][j]=max({l,mm,nn});
        
    }
    int maxMoves(vector<vector<int>>& grid) {
        int ans=0,i=0,n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<grid.size();i++){
           ans=max(ans, solve(grid,i,0,n,m,grid[0][i],dp));
        }
        return ans;
    }
}; 