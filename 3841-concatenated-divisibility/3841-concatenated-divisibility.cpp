class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int k,int state,vector<int>&temp,int cur,int rem){
        if(state==(1<<nums.size())-1)return rem==0;
        if(dp[state][cur]!=-1)return dp[state][cur];
        for(int i=0;i<nums.size();i++){
            if(state&(1<<i))continue;
            int newstate=state|(1<<i);
            int len=to_string(nums[i]).size();
            int powtenmod=pow(10,len);
            powtenmod%=k;
            auto newa=cur%k;
            auto newb=nums[i]%k;
            auto newnum=(newa*powtenmod+newb)%k;
            temp.push_back(nums[i]);
            if(solve(nums,k,newstate,temp,newnum,newnum))return 1;
            temp.pop_back();
        }return dp[state][cur]=0;
    }
    vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
        dp.resize((1<<nums.size())+1,vector<int>(k+1,-1));
        sort(nums.begin(),nums.end());
        vector<int>temp;
        solve(nums,k,0,temp,0,0);
        return temp;
    }
};