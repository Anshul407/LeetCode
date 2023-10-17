class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        int cntf=0;
        int cnt=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                  vis[i][j]=0;
                }
                if(grid[i][j]==1){
                    cntf++;

                }
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
int tm=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(t,tm);
            q.pop();

            for(int i=0;i<4;i++){
                int rw=r+dr[i];
                int cl=c+dc[i];
                if(rw>=0&&cl>=0&&rw<n&&cl<m&&vis[rw][cl]==0&&grid[rw][cl]==1){
                    q.push({{rw,cl},t+1});
                    vis[rw][cl]=2;
                    cnt++;
                }
            }
            

        }
        if(cnt!=cntf)return -1;
            
            return tm;
        
    }
};