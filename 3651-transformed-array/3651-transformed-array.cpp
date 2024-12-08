class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                int k=abs(nums[i]);
                k%=nums.size();
                if(i-k<0){
                    k-=i;
                    ans.push_back(nums[nums.size()-k]);
                }else ans.push_back(nums[i-k]);   
            }else if(nums[i]>0){
                int k=abs(nums[i]);
                k%=nums.size();
                if(i+k>=nums.size()){
                    k-=(nums.size()-i);
                    ans.push_back(nums[k]);
                }else ans.push_back(nums[i+k]);   

            }else if(nums[i]==0){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};