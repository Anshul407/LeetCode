class Solution {
public:
    int dp[1001];
    int solve(int n,int i,int s){
        if(i>n)return 0;
        if(n==i)return 1;
        if(s>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int tk=1;
        int ntk=1;
        if(s+i<=n){
            tk=s*solve(n,i+s,s);
        }
        ntk=solve(n,i,s+1);

        return dp[i]= max(tk,ntk);

        
    }
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,1);
    }
};