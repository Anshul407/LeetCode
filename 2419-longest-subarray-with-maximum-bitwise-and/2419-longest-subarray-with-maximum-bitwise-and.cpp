class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi= *max_element(nums.begin(),nums.end());
        int cnt=0,ans=0;
        for(auto it: nums){
            if(it==maxi)cnt++;
            else cnt=0;
            ans=max(ans,cnt);
        }
        return ans;
    }
};