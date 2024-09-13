class Solution {
public:
    void solve(vector<vector<int>>&g,int i,int j,int &a){
        if(i==0||j==0||i==g.size()-1||j==g[0].size()-1){
            a=0;
        }
        g[i][j]=-1;
        if(i>0){
            if(g[i-1][j]==0){
                solve(g,i-1,j,a);
            }
        }
        if(j>0){
            if(g[i][j-1]==0){
                solve(g,i,j-1,a);
            }
        }
        if(i<g.size()-1){
            if(g[i+1][j]==0){
                solve(g,i+1,j,a);
            }
        }
        if(j<g[0].size()-1){
             if(g[i][j+1]==0){
                solve(g,i,j+1,a);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    int a=1;
                    solve(grid,i,j,a);
                    if(a)ans++;
                }
            }
        }
        return ans;
    }
};