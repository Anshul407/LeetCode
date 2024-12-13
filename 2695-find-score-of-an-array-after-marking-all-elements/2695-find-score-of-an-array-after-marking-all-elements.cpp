class Solution {
public:
    long long findScore(vector<int>& nums) {
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        long long ans=0;
        vector<int>vis(nums.size(),0);
        for(auto i:mp){
            for(auto j:i.second){
                if(!vis[j]){
                    vis[j]=1;
                    ans=(long long)(ans+i.first);
                    if(j-1>=0)vis[j-1]=1;
                    if(j+1<nums.size())vis[j+1]=1;
                    
                }
            }
        }
        return ans;
    }
};