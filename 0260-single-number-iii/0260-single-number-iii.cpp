class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;

        }
        vector<int>a;
        for(auto i:mp){
            if(i.second==1){
                a.push_back(i.first);
            }
        }
        return a;
    }
};