class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int cur=1;
        for(int i=0;i<nums.size();i++){
            cur*=nums[i];
            ans=max(ans,cur);
            if(cur==0)cur=1;
        }
        cur=1;
        for(int i=nums.size()-1;i>=0;i--){
            cur*=nums[i];
            ans=max(ans,cur);
            if(cur==0)cur=1;
        }
        return ans;
    }
};