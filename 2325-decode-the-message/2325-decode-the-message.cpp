class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char>mp;
        char ch='a';
        for(auto i:key){

            if(mp.find(i)==mp.end()&&i!=' '){
                mp[i]=ch;
                ch++;
            }
        }
        string ans="";
        for(auto i:message){
            if(i==' ')ans.push_back(' ');
            else
            ans.push_back(mp[i]);
        }
        return ans;
    }

};