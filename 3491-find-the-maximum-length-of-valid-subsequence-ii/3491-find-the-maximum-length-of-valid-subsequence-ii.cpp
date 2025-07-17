class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int i,int k,int cur){
        if(i>=nums.size()-1)return 0;
        int ans=0;
        if(dp[i][cur+1]!=-1)return dp[i][cur+1];
        if(cur==-1){
            ans=max(ans,solve(nums,i+1,k,cur));
            for(int j=i+1;j<nums.size();j++){
                int curans=2+solve(nums,j,k,(nums[j]+nums[i])%k);
                ans=max(ans,curans);
            }
            return dp[i][cur+1]=ans;   
        }else{
        for(int j=i+1;j<nums.size();j++){
                if((nums[j]+nums[i])%k==cur){
                    int curans=1+solve(nums,j,k,cur);
                    ans=max(ans,curans);
                    return dp[i][cur+1]=ans;
            }
        }}
        return dp[i][cur+1]=0;
    }
    int maximumLength(vector<int>& nums, int k) {
        dp.resize(nums.size(),vector<int>(k+1,-1));
        return solve(nums,0,k,-1);
    }
};