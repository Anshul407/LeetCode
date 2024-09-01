class Solution {
public:
    vector<vector<double>>dp;
    double solve(vector<int>&nums,int k,int i)
    {   
        if(k>0&&i>=nums.size())return INT_MIN;
        if(k==0&&i>=nums.size())return 0;
        if(k<=0&&i!=nums.size())return INT_MIN;
        if(dp[i][k]!=-1)return dp[i][k];
        double tk=0;
        double m=INT_MIN;
        for(int j=i;j<nums.size();j++){
            tk+=nums[j];
            double cavg=tk/(j-i+1);
            double ans=solve(nums,k-1,j+1);
            if(ans!=INT_MIN){
                
                m=max(m,cavg+ans);
            }
            
        }
        return dp[i][k]= m;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        dp.resize(nums.size(),vector<double>(k+1,-1));
       return solve(nums,k,0);
    }
};