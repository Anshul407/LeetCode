class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        unordered_map<int,int>mp;
        int cnt=0;
        for(auto i:nums){
            if(i==0){
            cnt++;
            ans++;
            continue;
            }

            if(cnt>1){
                mp[cnt]++;   
            }
            cnt=0;
        }
        if(cnt>1)mp[cnt]++;
        for(auto i:mp){
            int num=i.first;
            int occ=i.second;
            long long nn=((num)*(num-1))/2;
            nn*=occ;
            ans+=nn;
        }
        return ans;

        
    }
};