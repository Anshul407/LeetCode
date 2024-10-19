class Solution {
public:
    unordered_map<int,int>dp;
    int solve(int x){
        if(x<0)return 1e9;
        if(x==1)return 0;
        if(dp[x])return dp[x];
        int op1=INT_MAX,op2=INT_MAX;
        if(x%2==0)op1=1+solve(x/2);
        else op2=1+solve(3*x+1);
        return dp[x]=min(op1,op2);
    }
    int getKth(int lo, int hi, int k) {
        vector<vector<int>>ans;
        for(int i=lo;i<=hi;i++){
            ans.push_back({solve(i),i});
        }
        sort(ans.begin(),ans.end());
        return ans[k-1][1];
    }
};