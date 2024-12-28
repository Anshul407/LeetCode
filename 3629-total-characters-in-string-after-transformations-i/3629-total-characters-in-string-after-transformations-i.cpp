class Solution {
public:
    const int mod=1e9+7;
   
    int lengthAfterTransformations(string s, int t) {
        vector<int>mp(26,0);
        for(auto i:s)mp[i-'a']++;
        for(int i=0;i<t;i++){
        vector<int>temp(26,0);
        for(int i=0;i<26;i++){
            if(mp[i]>0){
                if(i==25){
                    temp[1]=(temp[1]+mp[i])%mod;
                    temp[0]=(temp[0]+mp[i])%mod;
                }else {
                    temp[i+1]=(temp[i+1]+mp[i])%mod;
                }
            }
        }
        mp=temp;
       }
       int ans=0;
        for(auto i:mp){
        ans=(ans+i)%mod;
        }
        return ans;
    }
};