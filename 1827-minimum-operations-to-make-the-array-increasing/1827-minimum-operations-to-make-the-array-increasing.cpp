class Solution {
public:
    int minOperations(vector<int>& nums) {
        int curnum=nums[0];
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=curnum){ans=ans+(curnum-nums[i]+1);curnum=(curnum+1);}
            else{
                curnum=nums[i];
            }
        }
        return ans;
    }
};