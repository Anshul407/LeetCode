class Solution {
public:
    int dp[10001][10001];
    int solve(int n,int j){
        
        if(n==0)return 0;
        if(n<0||j*j>n)return INT_MAX;
        if(dp[n][j]!=-1)return dp[n][j];
        int tk=0;
        int ntk=0;

        
        tk=solve(n-j*j,j);
        if(tk!=INT_MAX)tk++;
        
        ntk=solve(n,j+1);

        return dp[n][j]= min(tk,ntk);
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
       return solve(n,1);
    }
};