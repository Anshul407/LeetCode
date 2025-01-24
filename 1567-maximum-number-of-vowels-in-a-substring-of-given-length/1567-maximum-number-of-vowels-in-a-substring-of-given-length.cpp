class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int ans=0;
        unordered_map<char,int>mp;
        int v=0;
        mp['a']=1;mp['i']=1;
        mp['e']=1;mp['o']=1;
        mp['u']=1;
        while(j<s.size()){
            if(mp[s[j]]==1){
                v++;
            }

            if(j-i+1==k){
                ans=max(ans,v);
                if(mp[s[i]]==1)v--;
                i++;
            }j++;
        }return ans;
    }
};