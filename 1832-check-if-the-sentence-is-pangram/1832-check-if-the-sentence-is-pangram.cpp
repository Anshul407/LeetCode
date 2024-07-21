class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int>mp;
        for(char ch='a';ch<='z';ch++){
            mp[ch]=0;
        }
        for(auto i:sentence){
            mp[i]++;
        }
        for(auto i:mp)if(i.second==0)return 0;

        return 1;
    }
};