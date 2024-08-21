class Solution {
public:
    int solve(vector<int>&stones,int i,int k, vector<vector<int>>&dp){
        if(i>=stones.size()-1)return 1;

        if(dp[i][k]!=-1)return dp[i][k];
        int c1=0,c2=0,c3=0;

       for(int j=i+1;j<stones.size();j++){
            if(stones[j]-stones[i]==k-1||stones[j]-stones[i]==k||stones[j]-stones[i]==k+1){
                c1=max(c1,solve(stones,j,stones[j]-stones[i],dp));
               
                if(c1)return dp[i][k]=1;
            }
       }
       

       return dp[i][k]=0;


    }
    bool canCross(vector<int>& stones) {
        int i=0;
        if(stones.size()>=2&&stones[1]-stones[0]>1)return 0;
        vector<vector<int>>dp(stones.size(),vector<int>(stones.size(),-1));
        return solve(stones,i,0,dp);
    }
};