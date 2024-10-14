class Solution {
public:
    int solve(vector<int>&nums,int i,vector<int>&vis){
        if(i>=nums.size())return 0;
       if(vis[i])return 0;
        vis[i]=1;
       return 1+solve(nums,nums[i],vis);
       
    }
    int arrayNesting(vector<int>& nums) {
        vector<int>vis(100000,0);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                ans=max(ans,solve(nums,i,vis));
            }
        }
        return ans;
    }
};