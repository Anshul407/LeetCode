class Solution {
public:
    vector<vector<int>>vis;
    bool solve(vector<vector<char>>&g,int i,int j,int p,int q,char x){
        if(vis[i][j]){
            if (i != p || j != q) return true;
        }

        vis[i][j]=1;
        bool a=0,b=0,c=0,d=0;
        if(i>0){
            if(g[i-1][j]==x&&(i-1!=p||j!=q)){
                a=solve(g,i-1,j,i,j,x);
            }
        }
        if(j>0){
            if(g[i][j-1]==x&&(i!=p||j-1!=q)){
               b= solve(g,i,j-1,i,j,x);
            }
        }
        if(i<g.size()-1){
            if(g[i+1][j]==x&&(i+1!=p||j!=q)){
               c= solve(g,i+1,j,i,j,x);
            }
        }
        if(j<g[0].size()-1){
             if(g[i][j+1]==x&&(i!=p||j+1!=q)){
               d= solve(g,i,j+1,i,j,x);
            }
        }
        return a||b||c||d;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        vis.resize(grid.size(),vector<int>(grid[0].size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(vis[i][j]==0){
                    if(solve(grid,i,j,-1,-1,grid[i][j]))return 1;
                }
            }
        }
        return 0;
    }
};