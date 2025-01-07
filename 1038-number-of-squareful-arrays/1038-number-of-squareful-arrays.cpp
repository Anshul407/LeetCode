class Solution {
public:
    map<int,int>mp;
    int solve(vector<int>&nums,int p,int state){
        if(state==(1<<nums.size())-1)return 1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(state&(1<<i))continue;
            if (i>0&&nums[i]==nums[i - 1]&&!(state&(1<<(i-1)))) {
                continue;
            }
            int curstate=state|(1<<i);
            if(p==-1){
                ans=ans+solve(nums,i,curstate);
            }else {
                int x=nums[p]+nums[i];
                int k=sqrt(x);
                if(k*k==x){
                    ans=ans+solve(nums,i,curstate);
                }
            }
        }
        return ans;
    }
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return solve(nums,-1,0);
    }
};