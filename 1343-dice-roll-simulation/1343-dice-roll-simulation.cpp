class Solution {
public:
    int dp[5001][8][16];
    const int mod=1e9+7;
    int solve(int n,vector<int>&r,int p,int cnt){
        if(n==0)return 1;
        if(dp[n][p+1][cnt]!=-1)return dp[n][p+1][cnt];
        int ans=0;
        for(int j=1;j<=6;j++){
            if(p==j&&r[p-1]-cnt>0){
                ans+=solve(n-1,r,j,cnt+1);
            }else if(p!=j) {
                ans=(ans%mod+solve(n-1,r,j,1)%mod)%mod;
            }
        }
        return dp[n][p+1][cnt]= ans%mod;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,-1,sizeof(dp));
        return solve(n,rollMax,-1,0);
    }
};