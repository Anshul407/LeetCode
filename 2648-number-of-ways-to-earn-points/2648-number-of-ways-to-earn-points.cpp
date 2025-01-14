class Solution {
public:
    const int mod=1e9+7;
    int dp[51][1001];
    int solve(int t,vector<vector<int>>&a,int cur,int i){
        if(cur==t)return 1;
        if(cur>t)return 0;
        if(i>=a.size())return 0;
        if(dp[i][cur]!=-1)return dp[i][cur];
        int ans=0;
        int cnt=0;
        int temp=a[i][1];
        while(cnt<a[i][0]){
            ans=(ans+solve(t,a,cur+temp,i+1))%mod;
            temp+=a[i][1];
            cnt++;
        }
        ans=(ans+solve(t,a,cur,i+1))%mod;
        
        return dp[i][cur]=ans%mod;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        memset(dp,-1,sizeof(dp));
        return solve(target,types,0,0);
    }
};