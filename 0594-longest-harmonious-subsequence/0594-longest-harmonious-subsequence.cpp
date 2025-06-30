class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums)mp[i]++;
        int ans=0;
        for(auto i:mp){
            if(mp.find(i.first+1)!=mp.end())
            {
                ans=max(ans,i.second+mp[i.first+1]);
            }
        }return ans;
    }
};