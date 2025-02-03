class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums,vector<int>&t,int i,int state){
        if(state==(1<<t.size())-1)return 0;
        if(i>=nums.size())return 1e6;
        if(dp[i][state]!=-1)return dp[i][state];
        int cur=nums[i];
        int ans=1e6;
        for(int x=0;x<t.size();x++){
            if(state&(1<<x))continue;
            int cost=0;
            int newcur=0;
            if(cur<t[x]){
                newcur=t[x];
                cost=t[x]-cur;
            }else if(cur>t[x]) {
                int rem=cur%t[x];
                if(rem!=0)
                cost=t[x]-rem;
                newcur=cur+cost;
            }else {
                cost=0;
                newcur=cur;
            }
            
            int curstate=state;
            for(int x=0;x<t.size();x++){
                 if(state&(1<<x))continue;
                 if(newcur%t[x]==0){
                    curstate=curstate|(1<<x);
                 }
            }
            ans=min(ans,cost+solve(nums,t,i+1,curstate));

        }
        ans=min(ans,solve(nums,t,i+1,state));
        return dp[i][state]= ans;
    }

    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        dp.resize(nums.size(),vector<int>(1<<target.size(),-1));
        return solve(nums,target,0,0);
    }
};