class Solution {
public:
    int solve(vector<int>&nums,int i,int j, vector<vector<vector<int>>>&dp,bool p){
        if(i>=j)return 0;

        if(dp[i][j][p]!=-1)return dp[i][j][p];
        int tk1=0,tk2=0;
        if(p){
        tk1=nums[i]+solve(nums,i+1,j,dp,!p);
        tk2=nums[j]+solve(nums,i,j-1,dp,!p);

        return dp[i][j][p]= max(tk1,tk2);
        }else{
            tk1=-nums[i]+solve(nums,i+1,j,dp,!p);
            tk2=-nums[j]+solve(nums,i,j-1,dp,!p);

        return dp[i][j][p]= min(tk1,tk2);
        }


    }
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<vector<int>>>dp(nums.size(),vector<vector<int>>(nums.size(),vector<int>(2,-1)));
        int ans=solve(nums,0,nums.size()-1,dp,true);

        return ans>=0;
    }
};