class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        map<int,int>mp;
        int psum=0;
        for(int i=1;i<nums.size();i++){
            psum=nums[i]+nums[i-1];
            if(mp.find(psum)!=mp.end())return true;

            mp[psum]++;
        }
        return 0;
    }
};