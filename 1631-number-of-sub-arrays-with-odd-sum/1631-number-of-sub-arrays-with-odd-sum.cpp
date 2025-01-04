class Solution {
public:
    const int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        vector<vector<int>>dp(arr.size()+1,vector<int>(2,0));
        int ans=0;
        vector<int>sum(arr.size(),0);
        sum[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            sum[i]=sum[i-1]+arr[i];
        }
        dp[0][0]=sum[0]%2==0;
        dp[0][1]=sum[0]%2!=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]%2==0){
                dp[i][0]=dp[i-1][0]+1;
                dp[i][1]=dp[i-1][1];
            }else {
                dp[i][0]=dp[i-1][1];
                dp[i][1]=dp[i-1][0]+1;
            }
        }
        for(int i=0;i<arr.size();i++){
            ans=(ans+dp[i][1])%mod;
        }
        return ans;
    }
};