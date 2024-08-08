class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;
        int f=0;
        
        for(int i=0;i<nums.size();i++){
            if(first<nums[i]){
                third=second;
                second=first;
                first=nums[i];
                
            }

            if(second<nums[i] && first!=nums[i]){
               
                third=second;
                second=nums[i];
                
            }
            if(third<=nums[i] && second!=nums[i]&&first!=nums[i]){
                third=nums[i];
                f=1;
            }
        }
        
        if(third==LLONG_MIN&&!f)return first;
        
        

        return third;
    }
};