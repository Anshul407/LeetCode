class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int i=0,j=0;
        while(i<grid.size()&&j<grid.size()){
            if(grid[i][j]==0)return 0;
            grid[i][j]=INT_MAX;
            i++;
            j++;
        }
        i=0,j=grid.size()-1;
        while(i<grid.size()&&j>=0){
             if(grid[i][j]==0)return 0;
             grid[i][j]=INT_MAX;
            i++;
            j--;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]!=0&&grid[i][j]!=INT_MAX)return 0;
            }
        }
        return 1;
    }
};