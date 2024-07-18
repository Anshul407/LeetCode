class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        int x=1e9;
        for(auto i:mp){
            if(x==1e9){
                x=i.second;
                continue;
            }
            else if(x!=i.second)return false;
        }
        return true;
    }
};