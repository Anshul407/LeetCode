class Solution {
public:
    int minimizedStringLength(string s) {
        map<char,int>mp;
        for(auto i:s)mp[i]++;
        return mp.size();
    }
};