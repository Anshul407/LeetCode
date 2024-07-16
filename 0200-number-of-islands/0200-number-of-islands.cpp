class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j){
        grid[i][j]='0';
        if(i!=0){
            int up=i-1;
            if(grid[up][j]=='1'){
                dfs(grid,up,j);
            }
        }
        if(j!=0){
            int up=j-1;
            if(grid[i][up]=='1'){
                dfs(grid,i,up);
            }
        }
        if(i<grid.size()-1){
            int up=i+1;
            if(grid[up][j]=='1'){
                dfs(grid,up,j);
            }
        }
        if(j<grid[0].size()-1){
            int up=j+1;
            if(grid[i][up]=='1'){
                dfs(grid,i,up);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
    }
};