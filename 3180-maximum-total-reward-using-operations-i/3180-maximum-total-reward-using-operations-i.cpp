class Solution {
public:
    int dp[2001][4000];
    int solve(vector<int>&v,int i,int p){
        if(i>=v.size())return 0;
        if(dp[i][p]!=-1)return dp[i][p];
        int tk=0,ntk=0;
        if(p<v[i]){
            tk=v[i]+solve(v,i+1,p+v[i]);
        }
        ntk=solve(v,i+1,p);
        return dp[i][p]= max(tk,ntk);
    }
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
        memset(dp,-1,sizeof(dp));
        return solve(rewardValues,0,0);
    }
};