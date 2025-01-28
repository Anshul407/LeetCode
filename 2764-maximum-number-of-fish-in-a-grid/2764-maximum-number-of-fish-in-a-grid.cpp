class Solution {
public:
    int solve(vector<vector<int>>&g,int i,int j){
        if(i<0||j<0||i>=g.size()||j>=g[0].size()||g[i][j]==0)return 0;
        int cur=g[i][j];
        g[i][j]=0;
        int op1=solve(g,i+1,j);
        int op2=solve(g,i-1,j);
        int op3=solve(g,i,j+1);
        int op4=solve(g,i,j-1);
        
        return cur+op2+op1+op3+op4;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>0){
                    ans=max(ans,solve(grid,i,j));
                }
            }
        }return ans;
    }
};