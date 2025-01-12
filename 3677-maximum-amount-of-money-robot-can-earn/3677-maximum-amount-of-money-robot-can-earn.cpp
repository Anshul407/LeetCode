class Solution {
public:
    int dp[501][501][3];
    int solve(vector<vector<int>>&c,int i,int j,int cur){
        if(i<0||j<0||i>=c.size()||j>=c[0].size())return -1e6;
        if(i==c.size()-1&&j==c[0].size()-1){
            if(c[i][j]<0){
            if(cur<2)return 0;
         }
            return c[i][j];

        }
        if(dp[i][j][cur]!=-1)return dp[i][j][cur];
        int op1=-1e6,op2=-1e6;
        
        if(c[i][j]<0){
            if(cur<2){
                op1=solve(c,i+1,j,cur+1);
                op2=solve(c,i,j+1,cur+1);
            }
            op1=max(op1,solve(c,i+1,j,cur)+c[i][j]);
            op2=max(op2,solve(c,i,j+1,cur)+c[i][j]);
               
            
        }else {
            op1=solve(c,i+1,j,cur)+c[i][j];
            op2=solve(c,i,j+1,cur)+c[i][j];
           
        }
        return dp[i][j][cur]= max(op1,op2);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        // if(coins.size()==1&&coins[0].size()==1)return max(0,coins[0][0]);
        memset(dp,-1,sizeof(dp));
        return solve(coins,0,0,0);
    }
};