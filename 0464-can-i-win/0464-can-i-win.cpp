class Solution {
public:
    vector<int>dp;
    int solve(int m,int d,int state){
        if(d<=0)return 0;
        if(dp[state]!=-1)return dp[state];
        int ans=0;
        for(int i=1;i<=m;i++){
            if(state&(1<<i))continue;
            if(solve(m,d-i,(state|(1<<i)))==0){
                return dp[state]=1;
            } 
        }
        return dp[state]= 0;
    }
    bool canIWin(int m, int d) {
        dp.resize(1<<m+1,-1);
        if(d<m)return 1;
        int s=0;
        for(int i=1;i<=m;i++){
            s+=i;
        }
        
        if(s<d)return 0;
        int state=0;
        return solve(m,d,state);
    }
};