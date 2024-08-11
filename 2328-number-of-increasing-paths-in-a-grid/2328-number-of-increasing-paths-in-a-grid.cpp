class Solution {
public:
    const int MOD=1e9+7;
    int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){
        if(dp[i][j]!=-1)return dp[i][j];
        
        int count=0;
        
        if(i>0){
            if(grid[i-1][j]>grid[i][j]){
                count+=solve(grid,i-1,j,dp)%MOD;
            }
        }
        if(j>0){
            if(grid[i][j-1]>grid[i][j]){
                count+=solve(grid,i,j-1,dp)%MOD;
            }
        }
        if(i<grid.size()-1){
            if(grid[i+1][j]>grid[i][j]){
                count+=solve(grid,i+1,j,dp)%MOD;
            }
        }
        if(j<grid[0].size()-1){
            if(grid[i][j+1]>grid[i][j]){
                count+=solve(grid,i,j+1,dp)%MOD;
            }
        }

        return dp[i][j]=(count+1)%MOD;
    }
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        int x=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                x=(x+solve(grid,i,j,dp))%MOD;
            }
        }
        return x%MOD;
    }
};