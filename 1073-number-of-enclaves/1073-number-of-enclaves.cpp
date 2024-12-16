class Solution {
public:
    void solve(vector<vector<int>>&v,int i,int j){
        if(i<0||j<0||i>=v.size()||j>=v[0].size()||v[i][j]==0)return ;
        v[i][j]=0;
        solve(v,i-1,j);
        solve(v,i+1,j);
        solve(v,i,j+1);
        solve(v,i,j-1);

    }
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            solve(grid,i,0);
        }
        int n=grid.size()-1;
        int m=grid[0].size()-1;
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==1)solve(grid,i,0);
            if(grid[i][m])solve(grid,i,m);
        }
        for(int i=0;i<grid[0].size();i++){
            if(grid[0][i]==1)solve(grid,0,i);
            if(grid[n][i]==1)solve(grid,n,i);
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j])ans++;
            }
        }
        return ans;


        
        
    }
};