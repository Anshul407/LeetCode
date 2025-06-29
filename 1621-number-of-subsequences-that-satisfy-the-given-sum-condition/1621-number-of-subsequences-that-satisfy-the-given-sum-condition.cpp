class Solution {
public:
    const int mod=1e9+7;
    vector<int>power;
    void help(){
        power[0]=1;
        for(int i=1;i<power.size();i++){
            power[i]=(power[i-1]*2LL)%mod;
        }
    }
    int numSubseq(vector<int>& nums, int target) {
        power.resize(nums.size());
        help();
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int ans=0;
        while(i<=j){
            if(nums[i]+nums[j]>target){
                j--;
            }else{
                long long cur=power[j-i];
                cur%=mod;
                ans=(ans+cur)%mod;
                i++;
            }
        }return ans;
    }
};