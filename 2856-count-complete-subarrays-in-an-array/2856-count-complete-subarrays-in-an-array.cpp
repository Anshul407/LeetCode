class Solution {
public:
    int solve(vector<int>&nums,int k){
        int i=0,j=0;
        int ans=0;
        map<int,int>mp;
        while(j<nums.size()){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums)mp[i]++;
        int k=mp.size();
        return solve(nums,k)-solve(nums,k-1);
    }
};