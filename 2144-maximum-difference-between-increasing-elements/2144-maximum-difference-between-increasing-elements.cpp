class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int curmin=INT_MAX;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if(i==0){
            curmin=min(curmin,nums[i]);
            continue;
            }
            if(nums[i]>curmin)
            ans=max(ans,nums[i]-curmin);
            curmin=min(curmin,nums[i]);
        }return ans;
    }
};