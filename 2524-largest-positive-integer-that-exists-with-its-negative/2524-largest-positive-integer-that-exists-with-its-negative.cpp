class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int>mp; int ans=-1;for(auto i:nums){if(mp.find(-1*i)!=mp.end()){ ans=max(ans,abs(i)); }mp[i]++;}
        return ans;
    }
};