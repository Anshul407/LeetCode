class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        map<int,int>cone,czero,rone,rzero;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    czero[j]++;
                    rzero[i]++;
                }else {
                    rone[i]++;
                    cone[j]++;
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]=rone[i]+cone[j]-rzero[i]-czero[j];
            }
        }
        return grid;
    }
};