class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        function<int(int,int)>solve=[&](int i,int j){
            if(i>j)return 0;
            if(dp[i][j]!=-1)return dp[i][j];
            int ans=0;
            for(int x=i;x<=j;x++){
                int left,right,leftans,rightans;
                if(i==0)left=1;
                else left=nums[i-1];
                if(j==nums.size()-1)right=1;
                else right=nums[j+1];

                leftans=solve(i,x-1);
                rightans=solve(x+1,j);
                int cur=left*right*nums[x];
                cur=cur+leftans+rightans;
                ans=max(ans,cur);
            }
            return dp[i][j]=ans;
        };

        return solve(0,nums.size()-1);
    }
};