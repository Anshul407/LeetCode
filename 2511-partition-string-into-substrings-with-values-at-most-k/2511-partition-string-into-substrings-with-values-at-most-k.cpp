class Solution {
public:
    int dp[100001];
    int solve(string &s,int k,int i,int p){
        if(i>=s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=984273;
        long long t=0;
        for(int j=i;j<s.size();j++){
            t=t*10+(s[j]-'0');
            if(t>k)break;
            if(t<=k){
                ans=min(ans,1+solve(s,k,j+1,p));
            }
        }
        return dp[i]= ans;
    }
    int minimumPartition(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(s,k,0,0)==984273?-1:solve(s,k,0,0);
    }
};