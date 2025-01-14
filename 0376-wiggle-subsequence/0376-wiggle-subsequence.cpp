class Solution {
public:
    int dp[1001][1001][2];
    int solve(vector<int>&nums,int i,int diff,int p,int cnt){
        if(i>=nums.size())return 0;
        int k=diff>0;
        if(dp[i][cnt][k]!=-1)return dp[i][cnt][k];
        int ntk=solve(nums,i+1,diff,p,cnt);
        int tk=0;
        if(cnt==0){
            
            tk=1+solve(nums,i+1,diff,i,cnt+1);
        }
        else if(cnt==1){
            diff=nums[i]-nums[p];
            if(diff<0||diff>0){
                tk=1+solve(nums,i+1,diff,i,cnt+1);
            }

        }
        else {
            if(diff<0&&nums[i]-nums[p]>0){
                tk=1+solve(nums,i+1,nums[i]-nums[p],i,cnt+1);
            }
            else if(diff>0&&nums[i]-nums[p]<0){
                tk=1+solve(nums,i+1,nums[i]-nums[p],i,cnt+1);
            }

        }
        return dp[i][cnt][k]= max(tk,ntk);
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0,-1,0);
    }
};