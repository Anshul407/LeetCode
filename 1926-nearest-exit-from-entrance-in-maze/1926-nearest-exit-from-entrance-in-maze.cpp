class Solution {
public:
    bool isexit(int i,int j,int x,int y,int n,int m){
        if(i==x&&j==y)return 0;

        if(i==0||j==0||i==n-1||j==m-1)return 1;

        return 0;
    }
    void dfs(vector<vector<char>> maze, int i,int j,int cnt,int &ans,int x,int y){
        if(isexit(i,j,x,y,maze.size(),maze[0].size())){
            ans=min(ans,cnt);
            return;
        }
        maze[i][j]='+';
        if(i!=0){
            int up=i-1;
            if(maze[up][j]=='.'){
                dfs(maze,up,j,cnt+1,ans,x,y);
            }
        }
        if(j!=0){
            int up=j-1;
            if(maze[i][up]=='.'){
                dfs(maze,i,up,cnt+1,ans,x,y);
            }
        }
        if(i<maze.size()-1){
            int up=i+1;
            if(maze[up][j]=='.'){
                dfs(maze,up,j,cnt+1,ans,x,y);
            }
        }
        if(j<maze[0].size()-1){
            int up=j+1;
            if(maze[i][up]=='.'){
                dfs(maze,i,up,cnt+1,ans,x,y);
            }
        }
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int i=entrance[0];
        int j=entrance[1];
        int cnt=0, ans=INT_MAX;
        dfs(maze,i,j,cnt,ans,i,j);
        if(ans==INT_MAX)return -1;
        return ans;
    }
};