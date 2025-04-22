class Solution {
public:
    const int mod=1e9+7;
    vector<unordered_map<int,int>>dp;
    int nn;
    vector<long long>fact,ifact;
    const int x=1e6+1;
    long long power(long long a, long long b, long long m) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
    }   
    void precomp(vector<long long>& fact, vector<long long>& ifact) {
        for (long long i = 1; i < x; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        ifact[x - 1] = power(fact[x - 1], mod - 2, mod);
        for (int i = x - 2; i >= 0; i--) {
            ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
        }
    }
    int solve(int n,int maxi,int p){
        if(n<=0)return 1;
        if(dp[n].find(p)!=dp[n].end())return dp[n][p];
        int ans=0;
        auto same=(((fact[nn-1] * ifact[n]) % mod) * ifact[nn - n-1]) % mod;
        for(int i=2*p;i<=maxi;i+=p){  
            ans+=solve(n-1,maxi,i);
            ans%=mod;   
        }return dp[n][p]= (ans+same)%mod;
    }
    int idealArrays(int n, int maxValue) {
        fact.resize(x,1);
        ifact.resize(x,1);
        precomp(fact,ifact);
        nn=n;
        dp.resize(n+1);
        int ans=0;
        for(int i=1;i<=maxValue;i++){
            auto cur=solve(n-1,maxValue,i);
            ans+=cur;
            ans%=mod;
        }
        return ans;
    }
};