class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        map<float,int>mp;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<j){
            auto x=(nums[i]+nums[j])/2.0;
            mp[x]++;
            i++;
            j--;
        }
        return mp.size();

    }
};