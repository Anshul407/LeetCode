class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        int mini=INT_MAX;
        int mini2=INT_MAX;
        for(auto i:nums1){
            mp[i]++;
            mini=min(i,mini);
        }
        for(auto i:nums2){
            if(mp.find(i)!=mp.end())return i;
             mini2=min(i,mini2);
        }

     

        if(mini2<mini){
            return mini2*10+mini;
        }
        else return mini*10+mini2;
    }
};