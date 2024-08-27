class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string,char>mp;
        int j=0;
        vector<string>x;
        for(int i=0;i<s.length();i++){
            string temp="";
            while(i<s.length()&&s[i]!=' '){
                temp+=s[i];
                i++;
            }
            x.push_back(temp);
        }
        for(auto i:x){
            if(mp.find(i)!=mp.end()&&mp[i]!=pattern[j])return 0;
            mp[i]=pattern[j];
            j++;
        }
        j=0;
        map<char,string>mp1;
        for(auto i:pattern){
            if(mp1.find(i)!=mp1.end()&&mp1[i]!=x[j])return 0;
            mp1[i]=x[j];
            j++;
        }
        return 1;
    }
};