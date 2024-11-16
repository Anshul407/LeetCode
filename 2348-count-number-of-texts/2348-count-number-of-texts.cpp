class Solution {
public:
    int dp[100001];
    const int mod=1e9+7;
    int solve(string &pr,int j){
        if(j>=pr.size())return 1;
        if(dp[j]!=-1)return dp[j];
        int ans=0;
        
            ans=(ans+solve(pr,j+1))%mod;
            if(j+1<pr.size()&&pr[j]==pr[j+1]){
                ans=(ans+solve(pr,j+2))%mod;
                if(j+2<pr.size()&&pr[j+2]==pr[j+1]){
                    ans=(ans+solve(pr,j+3))%mod;
                    if(j+3<pr.size()&&pr[j+3]==pr[j+1]&&(pr[j]=='7'||pr[j]=='9')){
                        ans=(ans+solve(pr,j+4))%mod;
                    }
                }
                
            }
        
        return dp[j]= ans%mod;
    }
    int countTexts(string pr) {
        memset(dp,-1,sizeof(dp));
        return solve(pr,0);
    }
};