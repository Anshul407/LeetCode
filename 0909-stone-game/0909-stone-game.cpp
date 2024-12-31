class Solution {
public:
    int solve(vector<int>& piles,int i,int j,bool alice,vector<vector<vector<int>>>&dp,int n){
        if(i>=n||j<0)return 0;
        int profit=0;
        if(dp[i][j][alice]!=-1)return dp[i][j][alice];
        if(alice){
            profit=max(piles[i]+solve(piles,i+1,j,false,dp,n),piles[j]+solve(piles,i,j-1,false,dp,n));
        }else {
            profit=max(piles[i]+solve(piles,i+1,j,true,dp,n),piles[j]+solve(piles,i,j-1,true,dp,n));
        }

        return dp[i][j][alice]=profit;
    }
    bool stoneGame(vector<int>& piles) {
        return 1;
    }
};