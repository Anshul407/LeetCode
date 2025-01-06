class Solution {
public:
    bool check(map<char,int>&mp,int k){
        int cur=0;
        int maxi=0;
        for(auto i:mp){
            cur+=i.second;
            maxi=max(i.second,maxi);
        }
        return cur-maxi<=k;
    }
    int characterReplacement(string s, int k) {
        int i=0,j=0;
        map<char,int>mp;
        int mini=INT_MAX;
        int ans=0;
        while(j<s.size()){
            mp[s[j]]++;
            while(check(mp,k)==false){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;

        }
        return ans;
    }
};