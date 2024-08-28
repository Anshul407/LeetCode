class Solution {
public:
    int bfs(vector<vector<int>>&grid,int i,int j,int n,int m){
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{i,j}});
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[i][j]=1;
        while(!q.empty()){
            int dist=q.front().first;
            int ii=q.front().second.first;
            int jj=q.front().second.second;
            q.pop();
           

            if(ii>0){
                if(!vis[ii-1][jj]&&!grid[ii-1][jj]){
                    q.push({dist+1,{ii-1,jj}});
                    vis[ii-1][jj]=1;
                }else if(grid[ii-1][jj])return dist;
            }
            if(jj>0){
                if(!vis[ii][jj-1]&&!grid[ii][jj-1]){
                    q.push({dist+1,{ii,jj-1}});
                    vis[ii][jj-1]=1;
                }else if(grid[ii][jj-1])return dist;
            }

            if(ii<n-1){
                if(!vis[ii+1][jj]&&!grid[ii+1][jj]){
                    q.push({dist+1,{ii+1,jj}});
                    vis[ii+1][jj]=1;
                }else if(grid[ii+1][jj])return dist;
            }
            if(jj<m-1){
                if(!vis[ii][jj+1]&&!grid[ii][jj+1]){
                    q.push({dist+1,{ii,jj+1}});
                    vis[ii][jj+1]=1;
                }else if(grid[ii][jj+1])return dist;
            }

        }
        return -1;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int ans=-1;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(!grid[i][j]){
                    ans=max(ans,bfs(grid,i,j,n,m));
                }
            }
        }
        return ans;
    }
};