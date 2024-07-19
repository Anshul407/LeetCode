class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(auto i:nums1){
            mp[i]++;
        }
        int ans=INT_MAX;
        for(auto i:nums2){
            if(mp.find(i)!=mp.end())ans=min(ans,i);
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};