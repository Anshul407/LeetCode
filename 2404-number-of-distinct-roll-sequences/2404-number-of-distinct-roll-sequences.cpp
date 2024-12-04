class Solution {
public:
    int gcd(int a,int b){
        if(a>b){
            return b==0?a:gcd(b,a%b);
        }else{
            return a==0?b:gcd(a,b%a);
        }
    }
    const int mod=1e9+7;
    int dp[10001][7][7];
    int solve(int n,int s,int p,int pp){
        if(s==n)return 1;
        if(dp[s][p][pp]!=-1)return dp[s][p][pp];
        int ans=0;
        for(int i=1;i<=6;i++){
            if(p==0||(p!=0&&pp!=i&&p!=i&&gcd(p,i)==1)){
                ans=(ans+solve(n,s+1,i,p))%mod;
            }
        
        }
        return dp[s][p][pp]=ans%mod;
    }
    int distinctSequences(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0,0);
    }
};