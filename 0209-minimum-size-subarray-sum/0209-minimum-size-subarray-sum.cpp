class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int cur=0;
        int ans=INT_MAX;
        while(j<nums.size()){
            cur+=nums[j];
            while(cur>=target){
                cur-=nums[i];
                ans=min(ans,j-i+1);
                i++;
            }
            j++;
        }return ans==INT_MAX?0:ans;
    }
};