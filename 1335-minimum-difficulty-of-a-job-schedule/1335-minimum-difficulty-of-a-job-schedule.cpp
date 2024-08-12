class Solution {
public:
    int solve(vector<int>& job, int i, int d, vector<vector<int>>& dp) {
        if(d==1){
           int m=job[i];
            for(int j=i;j<job.size();j++){
                m=max(m,job[j]);
                return m;
            }
        }
        if(dp[i][d]!=-1)return dp[i][d];
        int maxi=job[i];
        
        int res=INT_MAX;
        for(int j=i;j<=job.size()-d;j++){
            maxi=max(maxi,job[j]);

            res=min(res,maxi+solve(job,j+1,d-1,dp));

        }

        return dp[i][d]=res;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() < d) return -1;
        vector<vector<int>> dp(jobDifficulty.size(), vector<int>(d + 1, -1));
        return solve(jobDifficulty, 0, d, dp);
    }
};
