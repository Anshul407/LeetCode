class Solution {
public:
    const int mod=1e9+7;
    long long solve(long long n,long long cur){
        if(n==0)return 1;
        auto ans=solve(n/2,cur);
        ans=(ans*ans)%mod;
        if(n%2==1)ans=(ans*cur)%mod;
        return ans;
    }
    int countGoodNumbers(long long n) {
        auto a=solve(n/2+n%2,5);
        auto b=solve(n/2,4);
        return (a*b)%mod;
    }
};