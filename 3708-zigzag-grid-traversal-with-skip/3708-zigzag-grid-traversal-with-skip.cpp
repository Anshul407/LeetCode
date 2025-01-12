class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int f=1;
        vector<int>ans;
        for(int i=0;i<grid[0].size();i+=2){
            ans.push_back(grid[0][i]);
        }
        for(int i=1;i<grid[0].size();i+=2){
            grid[0][i]=INT_MAX;
        }
        for(int i=1;i<grid.size();i++){
            if(!f){
                for(int j=0;j<grid[0].size();j++){
                    if(i!=0&&(grid[i-1][j]!=INT_MAX))
                    grid[i][j]=INT_MAX;
                    else ans.push_back(grid[i][j]);
                }
                
                
            }else {
                for(int j=grid[0].size()-1;j>=0;j--){
                    if(i!=0&&(grid[i-1][j]!=INT_MAX))
                    grid[i][j]=INT_MAX;
                    else ans.push_back(grid[i][j]);
                    
                }
                
            }
            f=!f;
        }
        
        return ans;
    }
};