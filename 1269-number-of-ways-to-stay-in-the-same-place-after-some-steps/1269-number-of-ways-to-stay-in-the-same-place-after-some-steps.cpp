class Solution {
public:
    const int mod=1e9+7;
    vector<vector<long long>>dp;
    int solve(int n,int tot,int i ){
        if(i>=n){
            return 0;
        }
        
        long long op2=0,op3=0;
        if(tot==0)return i==0;
        if(dp[i][tot]!=-1)return dp[i][tot];
        long long op1=solve(n,tot-1,i);
        if(i!=n)
         op2=solve(n,tot-1,i+1);
        if(i!=0)
         op3=solve(n,tot-1,i-1);

        return dp[i][tot]=(op1+op2+op3)%mod;
    }
    int numWays(int steps, int arrLen) {
        dp.resize(arrLen+1,vector<long long>(steps+1,-1));
        return solve(arrLen,steps,0);
    }
};