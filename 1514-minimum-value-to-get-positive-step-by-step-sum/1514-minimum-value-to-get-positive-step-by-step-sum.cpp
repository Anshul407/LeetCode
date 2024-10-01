class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mini=INT_MAX;
        int sum=0;
        for(auto i:nums){
            sum+=i;
            mini=min(mini,sum);
        }
        if(mini<0)return abs(mini)+1;
        return 1;
    }
};