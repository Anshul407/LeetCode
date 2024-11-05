class Solution {
public:
    int dp[71][71][71];
    int solve(vector<vector<int>>&g,int i,int j,int k){
        if(i<0||j<0||i>=g.size()||j>=g[0].size()||k>=g[0].size()||k<0)return 0;
        if(i==g.size()-1){
            if(j==k)return g[i][j];
            return g[i][j]+g[i][k];
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int op1=solve(g,i+1,j-1,k-1);
        int op2=solve(g,i+1,j-1,k);
        int op3=solve(g,i+1,j-1,k+1);
        int op4=solve(g,i+1,j+1,k-1);
        int op5=solve(g,i+1,j,k+1);
        int op6=solve(g,i+1,j,k-1);
        int op7=solve(g,i+1,j,k);
        int op8=solve(g,i+1,j+1,k);
        int op9=solve(g,i+1,j+1,k+1);
        int cur=0;
        if(j==k)cur=g[i][j];
        else cur=g[i][j]+g[i][k];
        return dp[i][j][k]=cur+ max({op1,op2,op3,op4,op5,op6,op7,op8,op9});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,grid[0].size()-1);
    }
};