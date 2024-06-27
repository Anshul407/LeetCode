class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
            int left=-1;
            for(int j=0;j<grid[0].size();j++){
                for(int i=0;i<grid.size();i++){
                    if(grid[i][j]==1){left=j;break;}
                }
            }
            int right=-1;
            
            for(int j=grid[0].size()-1;j>=0;j--){
                for(int i=0;i<grid.size();i++){
                    if(grid[i][j]==1){right=j;break;}
                }
            }
            int up=-1;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j]==1){up=i;break;}
                }
            }
            int down=-1;
            for(int i=grid.size()-1;i>=0;i--){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j]==1){down=i;break;}
                }
            }
            cout<<up<<" "<<down;
            int b=abs(right-left)+1;
            int l=abs(up-down)+1;
            if(up==down&&right==left)return 1;
            return l*b;
        
    }
};