class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>&v,int i,int j,int n,int m){
        if(i>n||j>m)return 1e9;
        if(i==n&&j==m)return v[i][j]>0?1:1-v[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int op=0,op1=0;
        op1=solve(v,i+1,j,n,m);
        op=solve(v,i,j+1,n,m);
        int need=min(op1,op)-v[i][j];
        return dp[i][j]=max(1,need);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp,-1,sizeof(dp));
        int n=dungeon.size()-1,m=dungeon[0].size()-1;
        return solve(dungeon,0,0,n,m);
    }
};