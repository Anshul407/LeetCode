class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int k,int i,int p){
        if(i>=nums.size())return 0;
        if(dp[i][p+1]!=-1)return dp[i][p+1];
        int tk=INT_MIN;
        if(p==-1||i-p<=k){
           
            tk=nums[i]+solve(nums,k,i+1,i);
        }
        int ntk=solve(nums,k,i+1,p);
        return dp[i][p+1]= max(tk,ntk);
    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        dp.resize(nums.size(),vector<int>(nums.size()+1,-1));
        int ans= solve(nums,k,0,-1);
        
        if(ans==0){
            int maxi=INT_MIN;
            for(auto i:nums){
                maxi=max(i,maxi);
            }
            return maxi;
        }
        return ans;
    }
};