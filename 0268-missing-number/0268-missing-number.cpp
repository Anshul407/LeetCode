class Solution {
public:
    int missingNumber(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<=nums.size();i++)
        {
            mp[i]=-1;
        }
        for(auto i:nums){
            mp[i]=1;
        }
        for(auto i:mp){
            if(i.second==-1)return i.first;
        }
        return -1;
    }
};