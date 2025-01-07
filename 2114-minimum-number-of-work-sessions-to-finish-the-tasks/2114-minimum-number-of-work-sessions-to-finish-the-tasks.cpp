class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&t,int state,int cur,int st){
        if(state==(1<<t.size())-1)return 0;
        if(dp[cur][state]!=-1)return dp[cur][state];
        int ans=INT_MAX;
        for(int i=0;i<t.size();i++){
            if(state&(1<<i))continue;

            int curstate=state|(1<<i);
                int curr;
                if(cur+t[i]>st){
                    curr=1+solve(t,curstate,t[i],st);
                }else curr=solve(t,curstate,cur+t[i],st);
                ans=min(ans,curr);
        }
        return dp[cur][state]= ans;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        dp.resize(16,vector<int>(1<<tasks.size(),-1));
        return solve(tasks,0,0,sessionTime)+1;
    }
};
