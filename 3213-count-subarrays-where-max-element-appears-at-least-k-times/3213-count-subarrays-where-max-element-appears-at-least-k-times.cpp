class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int num=0;
        long long ans=0;
        for(auto i:nums)num=max(num,i);
        int i=0,j=0;
        map<int,int>mp;
        while(j<nums.size()){
            mp[nums[j]]++;
            while(mp[num]>=k){
                mp[nums[i]]--;
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        long long total=(long long)((long long)n*(n+1))/2;
        return total-ans;

        
    }
};