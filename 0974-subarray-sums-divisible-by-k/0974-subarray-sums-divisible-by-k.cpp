class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp;
        mp[0]++;
        int sum=0;
        int ans=0;
        for(auto i:nums){
            sum+=i;
            int mod = (sum % k + k) % k;
            //-5 % 5 = -5 (incorrect, should be 0 since -5 is divisible by 5) so (sum%k+k)%k =0 % 5 = 0
            if(mp.find(mod)!=mp.end())ans+=mp[mod];
            
            mp[mod]++;
        }
        return ans;
    }
};