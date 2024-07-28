class Solution {
public:
    int solve(vector<vector<int>>& triangle,int i,int j,int n,int col,vector<vector<int>>&dp){
        if(i>=n||j>=col)return INT_MAX;
        if(i==n-1)return triangle[i][j];
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        int down=INT_MAX,right=INT_MAX;
        if(i<n-1){
            down=solve(triangle,i+1,j,n,col+1,dp);
        }
        if(i<n-1){
            right=solve(triangle,i+1,j+1,n,col+1,dp);
        }

        return dp[i][j]= min(down,right)+triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        return solve(triangle,0,0,n,1,dp);
    }
};