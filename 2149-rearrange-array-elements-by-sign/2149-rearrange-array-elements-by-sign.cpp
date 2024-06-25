class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                if(ans.empty())ans.push_back(nums[i]);
                else{
                    ans.push_back(-1);
                    ans.push_back(nums[i]);
                }
            }
            
        }
        int j=1;
        for(auto i:nums){
            if(j>=ans.size()&&i<0){
                ans.push_back(i);
            }
            if(i<0){
                ans[j]=i;
                j+=2;
            }
        }
        return ans;
    }
};