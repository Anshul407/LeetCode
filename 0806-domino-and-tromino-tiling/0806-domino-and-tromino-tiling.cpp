class Solution {
public:
    const int mod=1e9+7;
    int dp[1001][1001];
    int solve(int i,int j){
        if(i==0&&j==0)return 1;
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(i==j){
        ans=(ans+solve(i-1,j-1))%mod;
        ans=(ans+solve(i-1,j-2))%mod;
        ans=(ans+solve(i-2,j-1))%mod;
        ans=(ans+solve(i-2,j-2))%mod;
        }
        else if(i>j){
        ans=(ans+solve(i-2,j))%mod;
        ans=(ans+solve(i-2,j-1))%mod;
        }else if(i<j){
        ans=(ans+solve(i-1,j-2))%mod;
        ans=(ans+solve(i,j-2))%mod;
        }
        return dp[i][j]=ans%mod;
    }
    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,n);
    }
};