class Solution {
public:
    int dp[101][101][202];
    int solve(vector<vector<char>>& g,int i,int j,int op){
        if(op<0||i>=g.size()||j>=g[0].size()||g[i][j]=='c')return 0;
        if(i==g.size()-1&&j==g[0].size()-1){
            if(g[i][j]=='(')return 0;
            return op==1;
        }
        if(dp[i][j][op]!=-1)return dp[i][j][op];
        
        int op1=solve(g,i+1,j,g[i][j]=='('?op+1:op-1);
        if(op1)return dp[i][j][op+1]=1;
        int op2=solve(g,i,j+1,g[i][j]=='('?op+1:op-1);
        if(op2)return dp[i][j][op]=1;
        return dp[i][j][op]= op1||op2;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,0);
    }
};