class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long>ind(primes.size(),1);
        vector<long long>dp(n+1);
        dp[1]=1;
        for(int i=2;i<=n;i++){
            long long mini=LLONG_MAX;
            for(int ii=0;ii<primes.size();ii++){
                mini=min(mini,dp[ind[ii]]*primes[ii]);
            }
            for(int ii=0;ii<primes.size();ii++){
                if(mini==dp[ind[ii]]*primes[ii]){ind[ii]++;}
            }
            dp[i]=mini;
        }
        return dp[n];
    }
};