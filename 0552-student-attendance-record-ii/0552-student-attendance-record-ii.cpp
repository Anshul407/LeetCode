class Solution {
public:
    int dp[100001][2][3];
    const int MOD=1e9+7;
    int solve(int n,int a,int s,int l){
        if(s==n){
            return a<2&&l<3;
        }
        if(dp[s][a][l]!=-1)return dp[s][a][l];
        long long op1=0,op2=0,op3=0;
        op1=(solve(n,a,s+1,0))%MOD;
        if(l<2)
        op2=(solve(n,a,s+1,l+1))%MOD;
        if(a<1)
        op3=(solve(n,a+1,s+1,0))%MOD;

        return dp[s][a][l]=(op1+op2+op3)%MOD;
            }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0,0);
    }
};