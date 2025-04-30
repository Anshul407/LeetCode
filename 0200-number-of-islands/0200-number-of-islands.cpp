class Solution {
public:
    void solve(vector<vector<char>>&g,int i,int j){
        if(i<0||j<0||i>=g.size()||j>=g[0].size()||g[i][j]=='0')return ;
        g[i][j]='0';
        solve(g,i-1,j);
        solve(g,i+1,j);
        solve(g,i,j-1);
        solve(g,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    ans++;
                    solve(grid,i,j);
                }
            }
        }return ans;
    }
};