class Solution {
public:
    vector<vector<long long>>dp;
    long long solve(vector<int>&a,vector<int>&b,int i,int j){
        if(j>=a.size())return 0;
        if(i>=b.size()){
            return INT_MIN;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        long long ntk=solve(a,b,i+1,j);
        long long tk= (long long )b[i]*a[j]+solve(a,b,i+1,j+1);
       
       
        
        return dp[i][j]=max(tk,ntk);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        dp.resize(b.size(),vector<long long>(a.size(),-1));
        return solve(a,b,0,0);
    }
};