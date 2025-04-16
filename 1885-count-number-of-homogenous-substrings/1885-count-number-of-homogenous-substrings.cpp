class Solution {
public:
    const int mod = 1e9+7;
    int countHomogenous(string s) {
        int ans=0;
        int i=0,j=0;
        unordered_map<char,int>mp;
        while(j<s.size()){
            mp[s[j]]++;
            while(mp.size()>1){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            ans+=(j-i+1);
            ans%=mod;
            j++;
        }return ans;
    }
};