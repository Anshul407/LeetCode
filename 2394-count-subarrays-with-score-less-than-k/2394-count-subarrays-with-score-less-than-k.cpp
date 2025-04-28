class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i=0,j=0;
        long long c=0;
        long long ans=0;
        while(j<nums.size()){
            c+=nums[j];

            while(c*(j-i+1)>=k){
                c-=nums[i];
                i++;
            }
            ans+=(j-i+1);

            j++;
        }

        return ans;


    }
};