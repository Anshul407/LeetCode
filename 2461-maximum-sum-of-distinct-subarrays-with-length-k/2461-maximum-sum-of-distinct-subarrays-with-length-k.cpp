class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        unordered_map<int,int>mp;
        int window=0;
        int i=0,j=0;
        long long cursum=0;
        while(i<nums.size()&&j<nums.size()){
            window++;
            cursum+=nums[j];
            mp[nums[j]]++;

            if(window==k){
                if(mp.size()==k){
                    ans=max(ans,cursum);
                }
                if(mp[nums[i]]==1)mp.erase(nums[i]);
                else mp[nums[i]]--;
                cursum-=nums[i];
                i++;
                window--;
                


            }
            j++;
        }
        return ans;
    }

};