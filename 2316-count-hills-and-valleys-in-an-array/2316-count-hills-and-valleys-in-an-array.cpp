class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=1;i<n-1;i++){
            int j=i-1;
            int k=i+1;
            if(nums[i]==nums[j]) continue;
            while(j>=0 && nums[j]==nums[i]){
                j--;
            }
            while(k<n && nums[k]==nums[i]){
                k++;
            }
            if(j>=0 && k<n){
                if(nums[i]>nums[j] && nums[i]>nums[k]){
                    ans++;
                }
                else if(nums[i]<nums[j] && nums[i]<nums[k]){
                    ans++;
                }
            }
            
        }
        return ans;
    }
};