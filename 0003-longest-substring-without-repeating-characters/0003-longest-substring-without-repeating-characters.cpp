class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        map<char,int>mp;
        int ans=0;
        while(j<s.size()){
            mp[s[j]]++;
            while(mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }return ans;
    }
};