class Solution {
public:
static bool cmp(vector<int>&p,vector<int>&q){
        return p[0]<q[0];
    }
    int getnext(vector<vector<int>>&ev,int i,int end){
        int j=ev.size()-1;
        int res=INT_MAX;
        while(i<=j){
            int mid=(i+j)/2;
            if(ev[mid][0]>end){
                res=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return res;
    }
    int solve(vector<vector<int>>&ev,int i, vector<vector<int>>&dp,int window,int k){
        if(i>=ev.size())return 0;
        if(window>=k)return 0;

        if(dp[i][window]!=-1)return dp[i][window];
        int nextev=getnext(ev,i,ev[i][1]);
        int tk=0,ntk=0;
        tk=ev[i][2]+solve(ev,nextev,dp,window+1,k);
        ntk=solve(ev,i+1,dp,window,k);

        return dp[i][window]=max(tk,ntk);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        vector<vector<int>>dp(events.size(),vector<int>(k+1,-1));
        sort(events.begin(),events.end(),cmp);
        return solve(events,0,dp,0,k);
    }
};