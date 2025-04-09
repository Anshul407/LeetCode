class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(auto i:nums){
            if(i<k)return -1;
        }
        int ans=0;
        while(nums.back()>k){
            int n=nums.back();
            int c=k;
            for(int i=nums.size()-2;i>=0;i--){
                if(nums[i]<n){
                    c=nums[i];
                    break;
                }
                }
            for(int i=nums.size()-1;i>=0&&nums[i]>c;i--){
                nums[i]=c;
            }
            ans++;
        }
        return ans;
    }
};