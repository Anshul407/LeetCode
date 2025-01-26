class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector<int>cur(nums.size());
        cur[0]=nums[0];
        for(int i=1;i<nums.size();i++)cur[i]=cur[i-1]+nums[i];
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            if((cur.back()-cur[i]-cur[i])%2==0)cnt++;
        }return cnt;
    }
};