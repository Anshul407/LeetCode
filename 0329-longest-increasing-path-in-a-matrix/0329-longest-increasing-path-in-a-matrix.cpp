class Solution {
public:
    
    int dfs(vector<vector<int>>& matrix, int i, int j, int curans, int &ans, vector<vector<int>> &memo) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        curans++;
        int maxLength = 0;  
        
        if (i != 0 && matrix[i-1][j] > matrix[i][j]) {
            maxLength = max(maxLength, dfs(matrix, i-1, j, curans, ans, memo));
        }
        if (j != 0 && matrix[i][j-1] > matrix[i][j]) {
            maxLength = max(maxLength, dfs(matrix, i, j-1, curans, ans, memo));
        }
        if (i < matrix.size()-1 && matrix[i+1][j] > matrix[i][j]) {
            maxLength = max(maxLength, dfs(matrix, i+1, j, curans, ans, memo));
        }
        if (j < matrix[0].size()-1 && matrix[i][j+1] > matrix[i][j]) {
            maxLength = max(maxLength, dfs(matrix, i, j+1, curans, ans, memo));
        }
        
        memo[i][j] = maxLength + 1; 
        ans = max(ans, memo[i][j]);
        return memo[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), -1));
        if(matrix.size()==1&&matrix[0].size()==1)return 1;
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int curans=0,currans=0;
                
                
                ans=max(ans,dfs(matrix,i,j,curans,currans,memo));
            }
        }
        return ans;
    }
};