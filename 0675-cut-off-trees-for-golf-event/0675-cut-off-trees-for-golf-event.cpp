class Solution {
public:
    int bfs(int i,int j,int n,int m,vector<vector<int>>forest){
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(forest.size(),vector<int>(forest[0].size(),0));
        q.push({0,{i,j}});
        vis[i][j]=1;
        int cur=0;
        while(!q.empty()){
            auto ii=q.front().second.first;
            auto jj=q.front().second.second;
            auto cur=q.front().first;
            q.pop();
            
            if(ii==n&&jj==m)return cur;

            if(ii>0&&!vis[ii-1][jj]&&forest[ii-1][jj]){
                q.push({cur+1,{ii-1,jj}});
                vis[ii-1][jj]=1;
            }
            if(jj>0&&!vis[ii][jj-1]&&forest[ii][jj-1]){
                q.push({cur+1,{ii,jj-1}});
                vis[ii][jj-1]=1;
            }
            if(ii<forest.size()-1&&!vis[ii+1][jj]&&forest[ii+1][jj]){
                q.push({cur+1,{ii+1,jj}});
                vis[ii+1][jj]=1;
            }
             if(jj<forest[0].size()-1&&!vis[ii][jj+1]&&forest[ii][jj+1]){
                q.push({cur+1,{ii,jj+1}});
                vis[ii][jj+1]=1;
            }

        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<forest.size();i++){
            for(int j=0;j<forest[0].size();j++){
                if(forest[i][j]>1)v.push_back({forest[i][j],{i,j}});
            }
        }
        int ans=0;
        int x=0,y=0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            int nx=v[i].second.first;
            int ny=v[i].second.second;
            int c=bfs(x,y,nx,ny,forest);
            if(c==-1)return -1;
            forest[nx][ny]=1;
            x=nx,y=ny;
            ans+=c;
        }
        return ans;

    }
};