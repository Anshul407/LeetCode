class Solution {
public:
    bool check(map<char,int>&mp){
        for(auto x:mp){
            auto i=x.first;
            if(i-'a'>=0){
                if(mp.find(toupper(i))==mp.end())return 0;
            }else {
                if(mp.find(tolower(i))==mp.end())return 0;
            }
        }
        return 1;
    }
    string longestNiceSubstring(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            map<char,int>mp;
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                if(check(mp)){
                    if(j-i+1>ans.size()){
                        ans=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};