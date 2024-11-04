class Solution {
public:
    int isPrefixOfWord(string s, string se) {
        int i=0;
        int cnt=0;
        while(i<s.size()){
            while(i<s.size()&&s[i]==' ')i++;
            cnt++;
            if(i>=s.size())return -1;
            if(s[i]==se[0]&&s.substr(i,se.size())==se)return cnt;
            while(i<s.size()&&s[i]!=' ')i++;
        }
        return -1;
    }
};