class Solution {
public:
    const int mod=1e9+7;
    int dp[20001][6];
    int help(int a,int e,int i,int o,int u){
        if(a)return 0;
        if(e)return 1;
        if(i)return 2;
        if(o)return 3;
        return 4;
    }
    int solve(int n,int ii,int a,int e,int i,int o ,int u,int k){
        if(ii>n-1)return 1;
        
        int ans=0;
        int key=help(a,e,i,o,u);
        if(dp[ii][key]!=-1)return dp[ii][key];
        if(e||k){
            ans=(ans+solve(n,ii+1,1,0,0,0,0,0))%mod;
        }
        if(a||i||k){
            ans=(ans+solve(n,ii+1,0,1,0,0,0,0))%mod;
        }
        if(!i||k){
            ans=(ans+solve(n,ii+1,0,0,1,0,0,0))%mod;
        }
        if(u||i||k){
            ans=(ans+solve(n,ii+1,0,0,0,1,0,0))%mod;
        }
        if(a||k){
            ans=(ans+solve(n,ii+1,0,0,0,0,1,0))%mod;
        }
        return dp[ii][key]=ans%mod;
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0,0,0,0,0,1);
    }
};