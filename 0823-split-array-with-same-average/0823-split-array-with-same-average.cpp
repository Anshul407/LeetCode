class Solution {
public:
    long long sum;
    vector<unordered_map<string,int>>dp;
    int solve(vector<int>&nums,int i,int cnt,long long csum){
        if(i>=nums.size()){
            if(cnt==0||cnt==nums.size())return 0;
            int req=sum-csum;
            int reqsize=nums.size()-cnt;
            return csum*reqsize==req*cnt;
        }
        auto key=to_string(cnt)+"Anshul"+to_string(csum);
        if(dp[i].find(key)!=dp[i].end())return dp[i][key];
        int op1=solve(nums,i+1,cnt+1,csum+nums[i]);
        if(op1)return dp[i][key]= 1;
        int op2=solve(nums,i+1,cnt,csum);
        return dp[i][key]=op2;
    }
    bool splitArraySameAverage(vector<int>& nums) {
        dp.resize(nums.size()+1);
        for(auto i:nums)sum+=i;
        int f=0;
        for(int i=1;i<nums.size();i++){
            if((sum*i)%nums.size()==0){
                f=1;
                break;
            }
        }
        if(!f)return 0;
        return solve(nums,0,0,0);
    }
};