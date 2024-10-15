class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mp,mp2;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()&&mp[s[i]]!=t[i])return 0;
            if(mp2.find(t[i])!=mp2.end()&&mp2[t[i]]!=s[i])return 0;
            
            mp[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        return 1;
    }
};