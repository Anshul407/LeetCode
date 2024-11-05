class Solution {
public:
    int dp[1001][1001];
    int solve(vector<int>&s,int i,int j,int cur){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int op1=0,op2=0;
        if(cur<0)return 0;
        op1=cur-s[i]-solve(s,i+1,j,cur-s[i]);
        op2=cur-s[j]-solve(s,i,j-1,cur-s[j]);
        return dp[i][j]= max(op1,op2);
    }
    int stoneGameVII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        int cur=0;
        for(auto i:stones)cur+=i;
        return solve(stones,0,stones.size()-1,cur);
    }
};