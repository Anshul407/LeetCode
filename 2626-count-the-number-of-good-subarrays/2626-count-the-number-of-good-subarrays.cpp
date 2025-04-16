class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int i=0,j=0;
        long long ans=0,cnt=0;
        while(j<nums.size()){
            mp[nums[j]]++;
            cnt+=(mp[nums[j]]-1);
            while(cnt>=k){
                ans+=(nums.size()-j);
                mp[nums[i]]--;
                cnt-=(mp[nums[i]]);
                i++;
            }
            j++;
            

        }return ans;
    }
};