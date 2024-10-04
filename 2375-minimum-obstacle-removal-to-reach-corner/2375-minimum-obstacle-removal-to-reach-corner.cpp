class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        int ans=INT_MAX;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        vis[0][0]=1;
    
        while(!q.empty()){
            auto d=q.top().first;
            auto i=q.top().second.first;
            auto j=q.top().second.second;
            q.pop();
         
            if(i==grid.size()-1&&j==grid[0].size()-1)return d;

            if(i>0&&!vis[i-1][j]){
                q.push({d+grid[i-1][j],{i-1,j}});
                if(i-1!=grid.size()-1||j!=grid[0].size()-1){
                    vis[i-1][j]=1;
                }
            }
            if(j>0&&!vis[i][j-1]){
                q.push({d+grid[i][j-1],{i,j-1}});
                if(i!=grid.size()-1||j-1!=grid[0].size()-1){
                    vis[i][j-1]=1;
                }
            }
            if(j<grid[0].size()-1&&!vis[i][j+1]){
                q.push({d+grid[i][j+1],{i,j+1}});
                if(i!=grid.size()-1||j+1!=grid[0].size()-1){
                    vis[i][j+1]=1;
                }
            }
            if(i<grid.size()-1&&!vis[i+1][j]){
                q.push({d+grid[i+1][j],{i+1,j}});
                if(i+1!=grid.size()-1||j!=grid[0].size()-1){
                    vis[i+1][j]=1;
                }
            }
            


        }
        return -1;
    }
};