class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        map<int,long long>fin;
        vector<long long>dp(nums.size());
        fin[0]=1;
        vector<int>check;
        for(auto i:nums){
            check.push_back(i%modulo==k);
        }
        long long ans=0;
        for(int i=0;i<check.size();i++){
            if(i==0){
                dp[i]=check[i];  
            }
            else
            dp[i]=check[i]+dp[i-1];
            dp[i]%=modulo;
            ans+=fin[(dp[i]-k+modulo)%modulo];
            fin[dp[i]]++;
        }return ans;


    }
};