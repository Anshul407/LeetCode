class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum=0;
        for(auto i:nums){
            sum+=i;
        }
        int ans=0;
        ans+=abs(goal-sum)/limit;
        if(abs(goal-sum)%limit)ans++;
        return ans;
        
    }
};