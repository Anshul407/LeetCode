class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int mini=INT_MAX,mini2=INT_MAX;
        for(auto i:nums1){
            mini=min(i,mini);
        }
        for(auto i:nums2){
            mini2=min(i,mini2);
        }
        return mini2-mini;
    }
};