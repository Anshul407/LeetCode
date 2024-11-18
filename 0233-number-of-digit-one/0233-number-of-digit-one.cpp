class Solution {
public:
    string num;
    int dp[11][11][2];
    int solve(int i,int n,int p,int a,int b){
        if(p>=num.size())return a;
        if(dp[p][a][b]!=-1)return dp[p][a][b];
        int l=b?(num[p]-'0'):9;
        int ans=0;
        for(int j=0;j<=l;j++){
           
            if(j==1){
                ans=ans+solve(i*10+j,n,p+1,a+1,b&&(j==l));
            }else ans=ans+solve(i*10+j,n,p+1,a,b&&(j==l));
        }
        return dp[p][a][b]= ans;
    }
    int countDigitOne(int n) {
        num=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,n,0,0,1);
    }
};