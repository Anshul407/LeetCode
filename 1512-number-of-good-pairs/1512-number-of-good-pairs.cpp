class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int>mp;
        mp[nums[0]]++;
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]++;
            }else {ans+=mp[nums[i]];
            mp[nums[i]]++;}

        }
        return ans;
    }
};