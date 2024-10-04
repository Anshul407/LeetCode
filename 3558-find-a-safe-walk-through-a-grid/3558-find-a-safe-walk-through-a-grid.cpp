class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue<pair<int,pair<int,int>>>pq;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        if(grid[0][0]==1)health--;
        pq.push({health,{0,0}});
        while(!pq.empty()){
            auto h=pq.top().first;
            auto i=pq.top().second.first;
            auto j=pq.top().second.second;
            pq.pop();

            if(h<=0)continue;
            if(i==grid.size()-1&&j==grid[0].size()-1)return 1;

            if(i>0&&!vis[i-1][j]){
                if(i-1!=grid.size()-1||j!=grid[0].size()-1)
                vis[i-1][j]=1;
                int hh=h;
                if(grid[i-1][j])hh-=1;
                pq.push({hh,{i-1,j}});
            }
            if(i<grid.size()-1&&!vis[i+1][j]){
                 if(i+1!=grid.size()-1||j!=grid[0].size()-1)
                vis[i+1][j]=1;
                 int hh=h;
                if(grid[i+1][j])hh-=1;
                pq.push({hh,{i+1,j}});
            }
            if(j>0&&!vis[i][j-1]){
                if(i!=grid.size()-1||j-1!=grid[0].size()-1)
                vis[i][j-1]=1;
                 int hh=h;
                if(grid[i][j-1])hh-=1;
                pq.push({hh,{i,j-1}});
            }
            if(j<grid[0].size()-1&&!vis[i][j+1]){
                if(i!=grid.size()-1||j+1!=grid[0].size()-1)
                vis[i][j+1]=1;
                 int hh=h;
                if(grid[i][j+1])hh-=1;
                pq.push({hh,{i,j+1}});
            }
        }
        return 0;

    }
};