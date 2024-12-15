class Solution {
public:
    int dp[51][51][51][5];
    int solve(int x,int y,int z,int p){
        int op1=0;
        if(dp[x][y][z][p+1]!=-1)return dp[x][y][z][p+1];
        if(p==-1){
            if(x)
            op1=2+solve(x-1,y,z,1);
            if(y)
            op1=max(op1,2+solve(x,y-1,z,2));
            if(z)
            op1=max(op1,2+solve(x,y,z-1,3));
        }
        else if(p==1&&y){
            op1=(op1,2+solve(x,y-1,z,2));
        }else if(p==2){
            if(z)
            op1=max(op1,2+solve(x,y,z-1,3));
            if(x)
            op1=max(op1,2+solve(x-1,y,z,1));
        }else if(p==3){
            if(x)
            op1=max(op1,2+solve(x-1,y,z,1));
            if(z)
            op1=max(op1,2+solve(x,y,z-1,3));
        }

        return dp[x][y][z][p+1]= op1;
          
        
    }
    int longestString(int x, int y, int z) {
        memset(dp,-1,sizeof(dp));
        return solve(x,y,z,-1);
    }
};