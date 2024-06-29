class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]<target){ans+=(j-i);i++;}
            // else if(nums[i]+nums[j]==ans){i++;j--;}
            else j--;
        }
        return ans;
    }
};