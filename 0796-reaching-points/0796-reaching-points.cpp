class Solution {
public:
    int solve(int x,int y,int t,int p){
        if(x==t&&y==p)return 1;
        if(x>t||y>p)return 0;
        if(x==t&&(p-y)%x==0)return 1;
        if(y==p&&(t-x)%y==0)return 1;
        return solve(x,y,t%p,p%t);
    }
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        return solve(sx,sy,tx,ty);
    }
};