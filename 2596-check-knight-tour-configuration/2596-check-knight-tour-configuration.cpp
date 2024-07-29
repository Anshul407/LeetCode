class Solution {
public:
    void solve(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<int>>& pass){
        // grid[i][j]=-1;
        if(i-1>0&&j>0&&grid[i-2][j-1]==grid[i][j]+1){
            grid[i][j]=-1;
            
            solve(grid,i-2,j-1,n,m,pass);
        }
        if(i>0&&j-1>0&&grid[i-1][j-2]==grid[i][j]+1){
            grid[i][j]=-1;
            solve(grid,i-1,j-2,n,m,pass);
        }
        if(i<n-1&&j-1>0&&grid[i+1][j-2]==grid[i][j]+1){
            grid[i][j]=-1;
            solve(grid,i+1,j-2,n,m,pass);
        }
        if(i<n-2&&j>0&&grid[i+2][j-1]==grid[i][j]+1){
            grid[i][j]=-1;
            solve(grid,i+2,j-1,n,m,pass);
        }
        if(i-1>0&&j<n-1&&grid[i-2][j+1]==grid[i][j]+1){
            grid[i][j]=-1;
            solve(grid,i-2,j+1,n,m,pass);
        }
        if(i>0&&j<n-2&&grid[i-1][j+2]==grid[i][j]+1){
            grid[i][j]=-1;
            solve(grid,i-1,j+2,n,m,pass);
        }
        if(i<n-1&&j<n-2&&grid[i+1][j+2]==grid[i][j]+1){
            grid[i][j]=-1;
            solve(grid,i+1,j+2,n,m,pass);
        }
        if(i<n-2&&j<n-1&&grid[i+2][j+1]==grid[i][j]+1){
            grid[i][j]=-1;
            solve(grid,i+2,j+1,n,m,pass);
        }
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
                   
                    
        vector<vector<int>>pass=grid;
        int cnt=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pass[i][j]=cnt;
                cnt++;
                cout<<pass[i][j];
            }
        }
        
                   solve(grid,0,0,n,m,pass);
           
         
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=-1&&i!=0&&j!=0){
                    return 0;  
                }
            }
        }
        return 1;

    }
};