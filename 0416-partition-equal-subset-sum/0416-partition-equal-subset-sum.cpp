class Solution {
public:
    vector<vector<int>>dp;
    int generateSubset(int index,vector<int>& nums,vector<int>& current,int sum,int currSum,vector<int>& result){
        if(sum-currSum<currSum)return 0;
        if(index==nums.size())
        {
            return sum-currSum==currSum;
        }
        if(dp[index][sum-currSum]!=-1)return dp[index][sum-currSum];
        
        int op1=generateSubset(index+1,nums,current,sum,currSum,result);
        int op2=generateSubset(index+1,nums,current,sum,currSum+nums[index],result);

        return dp[index][sum-currSum]=op1||op2;


    }
    bool canPartition(vector<int>& nums) {
        vector<int> current;
        int sum=0;
        for(auto it:nums)
        {
            sum+=it;
        }
        vector<int> result;
        dp.resize(nums.size(),vector<int>(sum+1,-1));
       return generateSubset(0,nums,current,sum,0, result);
       
        
    }
};