class Solution {
public:
    int dp[1001][1001];
    int solve(vector<int>&nums,int i,int p){
        if(i>=nums.size())return 0;
        int key;
        if(p==INT_MAX)key=0;
        else key=p+500;
        if(dp[i][key]!=-1)return dp[i][key];
        int ans=0;
        for(int j=i+1;j<nums.size();j++){
            if(p==INT_MAX){
                int cur=1+solve(nums,j,nums[j]-nums[i]);
                ans=max(ans,cur);
            }else if(nums[j]-nums[i]==p){
                int cur=1+solve(nums,j,p);
                ans=max(ans,cur);
            }
        }return dp[i][key]= ans;

    }
    int longestArithSeqLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,solve(nums,i,INT_MAX));
        }return ans+1;
    }
};