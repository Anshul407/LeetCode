class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int x=INT_MIN;
        for(int j=0;j<grid[0].size();j++){
            int cur=grid[0][j];
            if(x==cur)return 0;
            x=INT_MIN;
            for(int i=0;i<grid.size();i++){
                  if(cur!=grid[i][j])return 0;
            }
            x=cur;
        }
        return 1;
    }
};