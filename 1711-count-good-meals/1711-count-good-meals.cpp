class Solution {
public:
    const int MOD=1e9+7;
    int countPairs(vector<int>& nums) {
        
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            
            for(int power = 1; power <= (1 << 21); power <<= 1){
                if(mp.find(power-nums[i])!=mp.end()){
                    ans=(ans+mp[power-nums[i]])%MOD;
                }
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};