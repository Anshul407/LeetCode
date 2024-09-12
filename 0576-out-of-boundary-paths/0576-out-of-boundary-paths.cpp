class Solution {
public:
    const int MOD=1e9+7;
    vector<vector<vector<int>>>dp;
    
    int solve(int m,int n,vector<vector<int>>&g,int i,int j,int maxi){
        if(i<0||j<0||i>=m||j>=n){
            return 1;
        }
        if(dp[i][j][maxi]!=-1)return dp[i][j][maxi];
        long long op1=0,op2=0,op3=0,op4=0;
        if(maxi>0)
        op1=solve(m,n,g,i-1,j,maxi-1);
        if(maxi>0)
        op2=solve(m,n,g,i+1,j,maxi-1);
        if(maxi>0)
        op3=solve(m,n,g,i,j-1,maxi-1);
        if(maxi>0)
        op4=solve(m,n,g,i,j+1,maxi-1);
        return dp[i][j][maxi]= (op1+op2+op3+op4)%MOD;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.resize(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        vector<vector<int>>grid(m,vector<int>(n,0));
       return solve(m,n,grid,startRow,startColumn,maxMove);
    }
};