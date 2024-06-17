class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int mini1=INT_MAX,mini2=INT_MAX;
        int maxi1=INT_MIN,maxi2=INT_MIN;
        for(auto i:nums){
            mini1=min(mini1,i);
            maxi1=max(maxi1,i);
        }
        for(auto i:nums){
            if(i!=mini1){
                mini2=min(mini2,i);
            }
            if(i!=maxi1){
                maxi2=max(maxi2,i);
            }
        }
        if(maxi2==INT_MIN||mini2==INT_MAX)return 0;
        return (maxi1*maxi2)-(mini1*mini2);
    }
};