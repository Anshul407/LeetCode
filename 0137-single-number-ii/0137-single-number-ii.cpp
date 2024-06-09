class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        int ans=0;
        for(auto i:nums){
            if((ans^i)==0&&cnt==0){
                cnt++;
            continue;
            }
            cnt=0;
            ans^=i;
        }
        return ans;
    }
};