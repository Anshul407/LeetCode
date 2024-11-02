class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&s,int i,int j){
        if(i>=s.size()-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int x=i+1;x<s.size();x++){
            if(s[x]-s[i]==j-1||s[x]-s[i]==j||s[x]-s[i]==j+1){
                if(solve(s,x,s[x]-s[i]))return dp[i][j]=1;
            }
        }
        return dp[i][j]= 0; 
    }
    bool canCross(vector<int>& stones) {
        dp.resize(stones.size(),vector<int>(stones.size(),-1));
        return solve(stones,0,0);
    }
};