class Solution {
public:
    int dp[203][203];
    const int mod=1e9+7;
    int solve(string s,int i,int p,vector<int>&vis){
        
        if(i>s.size())return 1;
        if(dp[i][p+1]!=-1)return dp[i][p+1];
        int ans=0;
        for(int j=0;j<=s.size();j++){
            if(!vis[j]){
            vis[j]=1;
            if(i==0)ans=(ans+solve(s,i+1,j,vis))%mod;
            else if(s[i-1]=='D'&&j<p)ans=(ans+solve(s,i+1,j,vis))%mod;
            else if(s[i-1]=='I'&&j>p)ans=(ans+solve(s,i+1,j,vis))%mod;
            vis[j]=0;
            }
        }
        return dp[i][p+1]=ans%mod;
    }
    int numPermsDISequence(string s) {
        memset(dp,-1,sizeof(dp));
        vector<int>vis(s.size()+1,0);
        return solve(s,0,-1,vis);
    }
};