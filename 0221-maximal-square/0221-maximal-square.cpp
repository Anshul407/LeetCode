class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<vector<char>>&m,int i,int j){
        if(i<0||j<0||i>=m.size()||j>=m[0].size()||m[i][j]!='1'){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int x=solve(m,i+1,j);
        int y=solve(m,i,j+1);
        int xx=solve(m,i+1,j+1);
        return dp[i][j]=1+min({xx,y,x});
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        dp.resize(matrix.size(),vector<int>(matrix[0].size(),-1));
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    ans=max(ans,solve(matrix,i,j));
                    if(ans==0)ans=1;
                }
            }
        }
        return ans*ans;
    }
};