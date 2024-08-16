class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        map<int,int>mp;
        int sum=0;
        mp[sum]=0;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                ans=min(ans,i-mp[target-nums[i]]);
            }
            sum+=nums[i];
            mp[sum]=i;
            
        }
        if(ans==INT_MAX)return 0;
        return ans;
    }
};