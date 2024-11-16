class Solution {
public:
    bool isGood(vector<int>& nums) {
        
        int n=*max_element(nums.begin(),nums.end());
        map<int,int>mp;
        for(int i=1;i<=n;i++){
            mp[i]=0;
        }
        for(auto i:nums){
            if(mp.find(i)==mp.end())return 0;
            mp[i]++;
        }
        for(int i=1;i<=n;i++){
            if(i!=n&&mp[i]!=1)return 0;
            if(i==n&&mp[i]!=2)return 0;
        }
        return 1;
    }
};