class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>diff(nums.size(),0);
        for(auto i:queries){
            diff[i[0]]++;
            if(i[1]+1<nums.size())diff[i[1]+1]--;
        }
        for(int i=1;i<diff.size();i++){
            diff[i]=diff[i-1]+diff[i];
        }
        for(int i=0;i<nums.size();i++){
            if(diff[i]<nums[i])return 0;
        }return 1;
    }
};