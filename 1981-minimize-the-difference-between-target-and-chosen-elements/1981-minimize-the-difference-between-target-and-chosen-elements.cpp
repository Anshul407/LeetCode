class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&g,int t,int i,int tk){
        if(i>=g.size())return abs(tk-t);
        int cur=INT_MAX;
        if(dp[i][tk]!=-1)return dp[i][tk];
        for(int x=0;x<g[0].size();x++){
            cur=min(cur,solve(g,t,i+1,tk+g[i][x]));
        }

        return dp[i][tk]= cur;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        dp.resize(mat.size(),vector<int>(500000,-1));
        return solve(mat,target,0,0);
    }
};