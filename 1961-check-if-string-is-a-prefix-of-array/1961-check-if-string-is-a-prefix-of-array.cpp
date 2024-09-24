class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string cur="";
        for(auto i:words){
            cur+=i;
            if(cur==s)return 1;
            if(cur.length()>s.length())return 0;
        }
        return 0;
    }
};