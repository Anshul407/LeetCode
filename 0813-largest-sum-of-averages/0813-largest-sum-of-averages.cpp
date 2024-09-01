class Solution {
public:
    double solve(vector<int>&nums,int k,int i)
    {   
        if(k>0&&i>=nums.size())return INT_MIN;
        if(k==0&&i>=nums.size())return 0;
        if(k<=0&&i!=nums.size())return INT_MIN;
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
        return m;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
       return solve(nums,k,0);
    }
};