class Solution {
public:
    int dp[103][103];
    int solve(vector<int>&c,int i,int j){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int x=i;x<=j;x++){
            int cur=c[j+1]-c[i-1];
            int forw=solve(c,i,x-1)+solve(c,x+1,j);
            ans=min(ans,cur+forw);
        }
        return dp[i][j]= ans;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return solve(cuts,1,cuts.size()-2);
    }
};