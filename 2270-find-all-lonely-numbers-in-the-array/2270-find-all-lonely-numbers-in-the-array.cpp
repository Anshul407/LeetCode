class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        vector<int>ans;
        for(auto i:mp){
            if(mp.find(i.first-1)==mp.end()&&mp.find(i.first+1)==mp.end()&&i.second==1)ans.push_back(i.first);
        }
        return ans;
    }
};