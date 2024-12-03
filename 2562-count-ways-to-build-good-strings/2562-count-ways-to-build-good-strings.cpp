class Solution {
public:
    int dp[100001];
    const int mod=1e9+7;
    int solve(int l,int h,int z,int o,int s){
        if(s>h)return 0;
        if(dp[s]!=-1)return dp[s];
        int ans=(s>=l)?1:0;
        ans=(ans+solve(l,h,z,o,s+z))%mod; 
        ans=(ans+solve(l,h,z,o,s+o))%mod;
        return dp[s]= ans%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        return solve(low,high,zero,one,0);
    }
};