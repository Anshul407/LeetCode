class Solution {
public:
    int solve(vector<vector<int>>&v,int i,int j){
        if(i<0||j<0||i>=v.size()||j>=v[0].size()||v[i][j]==0)return 0;

        int op1=0,op2=0,op3=0,op4=0;
        int k=v[i][j];
        v[i][j]=0;
        op1=k+solve(v,i+1,j);
        op2=k+solve(v,i-1,j);
        op3=k+solve(v,i,j-1);
        op4=k+solve(v,i,j+1);
        v[i][j]=k;
        return max({op1,op2,op3,op4});
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans=max(ans,solve(grid,i,j));
            }
        }
        return ans;
    }
};