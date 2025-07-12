class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int>mp;
        for(auto i:s)mp[i]++;
        for(auto i:t){
            if(mp.find(i)==mp.end())return i;
            mp[i]--;
            if(mp[i]==0)mp.erase(i);
        }
        char c='a';
        return c;
    }
};