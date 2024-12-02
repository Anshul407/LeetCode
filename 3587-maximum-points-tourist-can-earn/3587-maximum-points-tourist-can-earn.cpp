class Solution {
public:
    int dp[201][201];
    int solve(int i,int d,int n,int k,vector<vector<int>>& stayScore, vector<vector<int>>& travelScore){
        if(d>=k)return 0;
        if(dp[i][d]!=-1)return dp[i][d];
        int ans=0;
        for(int j=0;j<n;j++){
            if(j==i){
                ans=max(ans,stayScore[d][i]+solve(i,d+1,n,k,stayScore,travelScore));
            }
            else{
                ans=max(ans,travelScore[i][j]+solve(j,d+1,n,k,stayScore,travelScore));
            }
        }
        return dp[i][d]=ans;
    }
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++){
        ans=max(ans, solve(i,0,n,k,stayScore,travelScore));}
        return ans;
    }
};