class Solution {
public:
    long long solve(int n,vector<vector<int>>&c,int i,int p,int q, vector<vector<vector<long long>>>&dp){
        if(i>=n/2)return 0;
        if(dp[i][p+1][q+1]!=-1)return dp[i][p+1][q+1];
        long long ans=LLONG_MAX;
        for(int xx=0;xx<3;xx++){
            for(int yy=0;yy<3;yy++){
                if(xx==yy)continue;
                if(xx==p||yy==q)continue;
                long long curc=1LL*c[i][xx]+c[n-i-1][yy]+solve(n,c,i+1,xx,yy,dp);
                ans=min(ans,curc);
            }
        }
        return dp[i][p+1][q+1]=ans;
    }
    long long minCost(int n, vector<vector<int>>& cost) {
         vector<vector<vector<long long>>>dp(n/2,vector<vector<long long>>(4,vector<long long>(4,-1)));
        return solve(n,cost,0,-1,-1,dp);
    }
};