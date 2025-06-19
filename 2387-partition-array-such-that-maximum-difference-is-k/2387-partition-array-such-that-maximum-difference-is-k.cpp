class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int cur=nums[i];
            while(i<nums.size()&&nums[i]-cur<=k)i++;
            i--;
            ans++;
        }
        return ans;
    }
};
