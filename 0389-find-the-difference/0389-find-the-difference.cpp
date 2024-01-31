class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        for(auto i:t){
            mp[i]++;
        }
        for(auto i:mp){
            if(i.second%2!=0){
                return i.first;
                break;
            }
        }
        char ans;
        return ans;
    }
};