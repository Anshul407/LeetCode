class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int &an){
        an+=grid[i][j];
        grid[i][j]=0;

        if(i!=0){
            int up=i-1;
            if(grid[up][j]>0){
                dfs(grid,up,j,an);
            }
        }
        if(j!=0){
            int up=j-1;
            if(grid[i][up]){
                dfs(grid,i,up,an);
            }
        }
        if(i<grid.size()-1){
            int up=i+1;
            if(grid[up][j]>0){
                dfs(grid,up,j,an);
            }
        }
        if(j<grid[0].size()-1){
            int up=j+1;
            if(grid[i][up]){
                dfs(grid,i,up,an);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    int curans=0;
                    dfs(grid,i,j,curans);
                    ans=max(ans,curans);
                }
            }
        }
        return ans;
    }
};