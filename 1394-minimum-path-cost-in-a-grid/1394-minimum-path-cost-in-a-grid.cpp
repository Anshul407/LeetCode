class Solution {
public:
    int dp[52][52];
    int solve(vector<vector<int>>& grid,int i,int j, vector<vector<int>>& moveCost){
        if(i==grid.size()-1)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=0;k<grid[0].size();k++){
            int s=grid[i][j];
            ans=min(ans,grid[i][j]+moveCost[s][k]+solve(grid,i+1,k,moveCost));    
        }
        return dp[i][j]= ans;

    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int ans=INT_MAX;
        memset(dp,-1,sizeof(dp));
        for(int j=0;j<grid[0].size();j++){
            ans=min(ans,solve(grid,0,j,moveCost));
        }
        return ans;
    }
};