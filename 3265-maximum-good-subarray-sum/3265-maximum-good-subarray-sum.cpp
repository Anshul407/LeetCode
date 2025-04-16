class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<long long>pre(nums.size());
        pre[0]=nums[0];
        unordered_map<int,vector<int>>mp;
        mp[nums[0]].push_back(0);
        int p=1;
        if(nums[0]<0)p=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)p=0;
            pre[i]=pre[i-1]+nums[i];
            mp[nums[i]].push_back(i);
        }
        long long ans=LLONG_MIN;
        for(int i=0;i<nums.size();i++){
            auto cur=nums[i];
            auto c=cur+k;
            auto d=cur-k;   
            for(auto &xx:mp[c]){
                if(xx>i){
                if(i==0)ans=max(ans,pre[xx]);
                else ans=max(ans,pre[xx]-pre[i-1]);}
                else if(xx<i){
                    if(xx==0)ans=max(ans,pre[i]);
                    else ans=max(ans,pre[i]-pre[xx-1]);
                }
            }
            for(auto xx:mp[d]){
                if(xx>i){
                if(i==0)ans=max(ans,pre[xx]);
                else ans=max(ans,pre[xx]-pre[i-1]);}
                else if(xx<i){
                    if(xx==0)ans=max(ans,pre[i]);
                    else ans=max(ans,pre[i]-pre[xx-1]);
                }
            }
            if(p){
                if(mp.count(c))
                mp.erase(c);
            if(mp.count(d))
            mp.erase(d);}
           
        }return ans==LLONG_MIN?0:ans;

    }
};