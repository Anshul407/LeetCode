class Solution {
public:
    int dp[60001][2];
    unordered_map<int,int>mp;
    int solve(int &a,int &b,int &dest,int cur,int f){
        if(cur==dest)return 0;

        if(cur>6000||cur<0||mp.find(cur)!=mp.end()||f>=2)return 1e9;
        if(dp[cur][f]!=-1)return dp[cur][f];

        dp[cur][f]=1+solve(a,b,dest,cur+a,0);
        
        if(f==0&&cur-b>=0){
            dp[cur][f]=min(dp[cur][f],1+solve(a,b,dest,cur-b,f+1));
        }
        return  dp[cur][f];
        }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        memset(dp,-1,sizeof(dp));
        for(auto i:forbidden){
            mp[i]=1;
        }
        return (solve(a,b,x,0,0)>=1e9)?-1:solve(a,b,x,0,0);
    }
};