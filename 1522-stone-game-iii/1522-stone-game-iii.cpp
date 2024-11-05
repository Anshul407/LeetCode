class Solution {
public:
    int dp[50001][2];
    int solve(vector<int>&s,int i,int a){
        if(i>=s.size())return 0;
        if(dp[i][a]!=-1)return dp[i][a];
        int ans=0;
        int op;
        if(a)op=INT_MIN;
        else op=INT_MAX;
        for(int j=i;j<i+3&&j<s.size();j++){
            ans+=s[j];
            if(a){
                op=max(op,ans+solve(s,j+1,!a));
            }else op=min(op,-ans+solve(s,j+1,!a));

        }
        return dp[i][a]= op;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp));
        int val=solve(stoneValue,0,1);
        if(val==0)return "Tie";
        return val>0?"Alice":"Bob";
    }
};