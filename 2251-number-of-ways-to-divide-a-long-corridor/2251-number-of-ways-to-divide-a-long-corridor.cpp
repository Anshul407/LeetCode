class Solution {
public:
    int dp[100001];
    const int mod=1e9+7;
    int solve(string &c,int i,int cur){
        if(i>=c.size())return cur;
        int k=0;
        int ans=0;
        long long p=0;
        if(dp[i]!=-1)return dp[i];
        for(int j=i;j<c.size();j++){
            if(c[j]=='S')k++;
            if(j==c.size()-1&&k==2){
                ans+=solve(c,j+1,1);
                ans%=mod;
            }
            if(k==3){
                long long curans=solve(c,j,1);
                curans%=mod;
                curans*=p;
                ans=(ans%mod+curans%mod)%mod;
                ans%=mod;
                break;
            }
            if(k==2){
                p++;   
            }    
        }
        return dp[i]= ans;
    }
    int numberOfWays(string corridor) {
        memset(dp,-1,sizeof(dp));
        return solve(corridor,0,0);
    }
};