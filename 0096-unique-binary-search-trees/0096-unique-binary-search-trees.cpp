class Solution {
public:
    int dp[101];
    int solve(int n)
    {
        if(n==2||n==1)return n;
        if(n==0)return 1;
        int ans=0;
        if(dp[n]!=-1)return dp[n];
        for(int k=1;k<=n;k++){
            int left=solve(k-1);
            int right=solve(n-k);
            ans+=left*right;
            
        }

        return dp[n]=ans;
        
    }
    int numTrees(int n) {
        
        memset(dp,-1,sizeof(dp));
        return solve(n);

    }
};