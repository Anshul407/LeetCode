class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long>l(nums.size(),0);
        vector<long long>r(nums.size(),0);
        l[0]=nums[0];
        r[0]=nums.back();
        for(int i=1;i<nums.size();i++){
            l[i]=l[i-1]+nums[i];
        }
        reverse(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            r[i]=r[i-1]+nums[i];
        }
        int cnt=0;
        reverse(r.begin(),r.end());
        for(int i=0;i<nums.size()-1;i++){
            if(l[i]>=r[i+1])cnt++;
        }
        return cnt;

    }
};