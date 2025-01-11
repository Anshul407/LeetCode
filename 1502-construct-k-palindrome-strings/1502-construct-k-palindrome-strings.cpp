class Solution {
public:
    bool canConstruct(string s, int k) {
        map<char,int>mp;
        for(auto i:s)mp[i]++;
        if(s.size()<k)return 0;
        if(s.size()==k)return 1;
        for(auto i:mp){
            if(i.second%2!=0){
                k--;
            }
            if(k<0)return 0;
        }
        return 1;
    }
};