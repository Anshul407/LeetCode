class Solution {
public: 
    void dfs(vector<vector<int>>&grid,int i,int j,int n,int m){
        grid[i][j]=0;
        if(i>0){
            if(grid[i-1][j]==1){
                dfs(grid,i-1,j,n,m);
            }
        }
        if(j>0){
            if(grid[i][j-1]==1){
                dfs(grid,i,j-1,n,m);
            }
        }
        if(i<n-1){
            if(grid[i+1][j]==1){
                dfs(grid,i+1,j,n,m);
            }
        }
        if(j<m-1){
            if(grid[i][j+1]==1){
                dfs(grid,i,j+1,n,m);
            }
        }
    }
    int getnum(vector<vector<int>>grid){
        int n=grid.size(),m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cnt++;
                    dfs(grid,i,j,n,m);
                }
            }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        int x=getnum(grid);
        if(x>=2||x==0)return 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1){
                grid[i][j]=0;
                int numberofisland=getnum(grid);
                grid[i][j]=1;
                if(numberofisland>1||numberofisland<1)return 1;
            }
        }}
        return 2;
    }
};