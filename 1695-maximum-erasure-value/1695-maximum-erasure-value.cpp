class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int>mp;
        int i=0,j=0;
        int cur=0;
        int ans=0;
        while(i<nums.size()&&j<nums.size()){
            
            if(mp.find(nums[j])!=mp.end()&&mp[nums[j]]>0){
                ans=max(ans,cur);
                while(nums[i]!=nums[j]){
                    mp[nums[i]]--;  
                    if (mp[nums[i]] == 0) mp.erase(nums[i]);  
                    cur -= nums[i];  
                    i++;
                }
                cur-=nums[i];
                mp[nums[i]]--;
                i++;
                
            }cur += nums[j];
            mp[nums[j]]++;
            
            j++; 

            
        }
        return max(cur,ans);
    }
};