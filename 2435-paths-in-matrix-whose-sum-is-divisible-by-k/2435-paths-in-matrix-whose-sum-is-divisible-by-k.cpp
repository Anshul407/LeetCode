class Solution {
public:
    const int MOD=1e9+7;
    vector<vector<vector<long long>>>dp;
    int solve(int i,int j,vector<vector<int>>&g,int k,long long cur){
        if(i>=g.size()||j>=g[0].size())return 0;
       
        if(i==g.size()-1&&j==g[0].size()-1){
            
            return (cur+g[i][j])%k==0;
        }
         if(dp[i][j][cur%k]!=-1)return dp[i][j][cur%k];
        long long down=0,forw=0;
        down+=solve(i+1,j,g,k,cur+g[i][j]);
        forw+=solve(i,j+1,g,k,cur+g[i][j]);


        return dp[i][j][cur%k]= (down+forw)%MOD;
        }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        dp.resize(grid.size(),vector<vector<long long>>(grid[0].size(),vector<long long>(k+1,-1)));
        return solve(0,0,grid,k,0);
    }
};