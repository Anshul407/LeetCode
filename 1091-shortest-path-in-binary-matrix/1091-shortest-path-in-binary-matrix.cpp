class Solution {
public:
    vector<vector<int>> path = {
    {1, 0},   // down
    {-1, 0},  // up
    {0, 1},   // right
    {0, -1},  // left
    {1, 1},   // down-right
    {1, -1},  // down-left
    {-1, 1},  // up-right
    {-1, -1}  // up-left
};

bool issafe(int i, int j, int n, int m) {
    return (i >= 0 && j >= 0 && i < n && j < m);
}


    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        if(grid.size()==1||grid[0].size()==1)return -1;
        if(grid[0][0]==1)return -1;

        q.push({0,0});
        int step=1;
        grid[0][0]=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                int x=it.first;
                int y=it.second;
                if(x==n-1&&y==m-1)return step;
                for(auto dir:path){
                    int newx=x+dir[0];
                    int newy=y+dir[1];
                    if(issafe(newx,newy,n,m)&&grid[newx][newy]==0){
                        grid[newx][newy]=1;
                        q.push({newx,newy});
                    }
                }

               
            }
             step++;
        }


        return -1;
        
    }
};