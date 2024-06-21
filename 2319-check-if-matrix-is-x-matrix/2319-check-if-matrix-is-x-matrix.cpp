class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int i=0,j=0;
        int sum=0;
        while(i<grid.size()&&j<grid.size()){
            if(grid[i][j]==0)return 0;
            sum+=grid[i][j];
            i++;
            j++;
        }
        i=0,j=grid.size()-1;
        while(i<grid.size()&&j>=0){
            
             if(grid[i][j]==0)return 0;
            if(i!=j)
            sum+=grid[i][j];
            i++;
            j--;
        }
        int total_sum=0;
        for (const auto& row : grid) {
        total_sum += std::accumulate(row.begin(), row.end(), 0);
    }
    
        return total_sum==sum;
    }
};