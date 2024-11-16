class Solution {
public:
    int dp[201][201];
    int solve(int i,int j){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
            int res=k+max(solve(i,k-1),solve(k+1,j));
            ans=min(ans,res);
        }
        return dp[i][j]=ans;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(1,n);
    }
};