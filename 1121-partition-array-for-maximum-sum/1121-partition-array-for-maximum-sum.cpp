class Solution {
public:
    int kk;
    const int mod=1e9+7;
    vector<int> a;
    int dp[501];
    int fnc(int i)
    {
        if(i==a.size())
        return 0;
        if(dp[i]!=-1)return dp[i];
        long long ans=0;
        int maxi=0;
        for(int j=i;j<i+kk&&j<a.size();j++)
        {
            maxi=max(maxi,a[j]);
            int cur=maxi*(j-i+1)+fnc(j+1);
            ans=max(ans,(long long)cur);
        }
        return dp[i]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        a=arr;
        kk=k;
        return fnc(0);
    }
};