class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2)q.push({i,j}),grid[i][j]=3;

            }
        }
        int ans=-1;
        while(!q.empty()){
            auto cur=q.size();
            ans++;
            for(int p=0;p<cur;p++){
                auto x=q.front();
                q.pop();
                int i=x.first;
                int j=x.second;
                if(i-1>=0&&grid[i-1][j]==1)grid[i-1][j]=3,q.push({i-1,j});
                if(j-1>=0&&grid[i][j-1]==1)grid[i][j-1]=3,q.push({i,j-1});
                if(i+1<grid.size()&&grid[i+1][j]==1)grid[i+1][j]=3,q.push({i+1,j});
                if(j+1<grid[0].size()&&grid[i][j+1]==1)grid[i][j+1]=3,q.push({i,j+1});
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)return -1;

            }
        }
        if(ans==-1)return 0;
        return ans;
    }
};