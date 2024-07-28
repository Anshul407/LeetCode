class Solution {
public:
    int solve(vector<vector<int>>& matrix,int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i>=n||j>=m)return INT_MAX;
        if(i==n-1){
            return matrix[i][j];
        }
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        int left = INT_MAX, right = INT_MAX, down = INT_MAX;
        if(i<n-1){
            down=solve(matrix,i+1,j,n,m,dp);
        }
        if(i<n-1&&j<m-1){
            right=solve(matrix,i+1,j+1,n,m,dp);
        }
        if(i<n-1&&j>0){
            left=solve(matrix,i+1,j-1,n,m,dp);
        }

        return dp[i][j]=min(down,min(left,right))+matrix[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        int ans=INT_MAX;
        for(int i=0;i<matrix.size();i++){
           ans=min(ans, solve(matrix,0,i,n,n,dp));
        }
        return ans;
    }
};