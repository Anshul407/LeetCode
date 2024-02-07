class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        
        int sum=((n)*(n+1))/2;
        int sum2=0;
        for(auto x:nums){
            sum2+=x;
        }
        return abs(sum2-sum);
    }
};