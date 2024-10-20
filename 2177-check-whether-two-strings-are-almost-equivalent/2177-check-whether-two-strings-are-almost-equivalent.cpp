class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        map<char,int>mp,mp2;
        for(auto i:word1){
            mp[i]++;
        }
        for(auto i:word2){
            mp2[i]++;
        }
         
        for(auto i:mp){
           if(abs(mp2[i.first]-i.second)>3)return 0;
        
        }
        for(auto i:mp2){
           if(abs(mp[i.first]-i.second)>3)return 0;
        
        }
        return 1;
    }
};