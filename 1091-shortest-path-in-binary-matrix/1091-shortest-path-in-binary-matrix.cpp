class Solution {
public:
    vector<vector<int>> direction = {
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
    typedef pair<int, pair<int, int>> P;
    int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0 || grid[0][0] != 0)
            return -1;

        auto isSafe = [&](int x, int y) {
            return x>=0 && x<m && y>=0 && y<n;
        };
        
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int d=it.first;
            int x=it.second.first;
            int y=it.second.second;
            for(auto dir:direction){
                int newx=x+dir[0];
                int newy=y+dir[1];
                int dist=1;
                if(isSafe(newx,newy) && grid[newx][newy] == 0 && d+dist < result[newx][newy]){
                    grid[newx][newy]=1;
                    pq.push({d+dist,{newx,newy}});
                    result[newx][newy]=d+dist;

                    

                }

            }

        
        }

        if(result[n-1][m-1]==INT_MAX)return -1;

        return result[n-1][m-1]+1;
        
    }
};