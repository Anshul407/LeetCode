class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int i=0;
        int ans=0;
        while(i<nums.size()){
            int p=0;
            int cur=0;
            while(i<nums.size()&&nums[i]>p){
            
                cur+=nums[i];
                p=nums[i];
                i++;
            }
            ans=max(ans,cur);
        }
        return ans;
    }
};