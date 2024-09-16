class Solution {
public:
    void solve(vector<vector<int>>&g,int i,int j,int &ans){
         if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == 0) {
           
            ans++;
            return;
        }
        if (g[i][j] == 2) return;  
        
        g[i][j] = 2; 
        
        solve(g, i - 1, j, ans);  // Up
        solve(g, i + 1, j, ans);  // Down
        solve(g, i, j - 1, ans);  // Left
        solve(g, i, j + 1, ans);  // Right
        

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int ans=0;
                if(grid[i][j]){
                solve(grid,i,j,ans);
                return ans;
                }
            }
        }
        return 0;
    }
};