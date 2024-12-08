class Solution {
public:
    string greatestLetter(string s) {
        map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        string ans="";
        for(char x='z';x>='a';x--){
            if(mp.find(x)!=mp.end()&&mp.find(toupper(x))!=mp.end()){
                ans.push_back(toupper(x));
                break;
            }
        }
        return ans;
    }
};