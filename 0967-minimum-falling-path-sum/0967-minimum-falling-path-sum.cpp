class Solution {
public:
    int solve(vector<vector<int>>&m,int i,int j,vector<vector<int>>&dp){
        if(i<0||j<0||i>=m.size()||j>=m[0].size())return 1e9;
        if(i==m.size()-1)return m[i][j];
        if(dp[i][j]!=-1)return dp[i][j];

        int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
        op1=m[i][j]+solve(m,i+1,j-1,dp);
        op2=m[i][j]+solve(m,i+1,j,dp);
        op3=m[i][j]+solve(m,i+1,j+1,dp);

        return dp[i][j]=min({op1,op2,op3});

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        int ans=INT_MAX;
        for(int i=0;i<matrix[0].size();i++){
            ans=min(ans,solve(matrix,0,i,dp));
        }
        return ans;
    }
};