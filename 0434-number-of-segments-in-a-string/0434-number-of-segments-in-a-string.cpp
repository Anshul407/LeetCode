class Solution {
public:
    int countSegments(string s) {
        int i=0;
        int cnt=0;
        while(i<s.length()){
            while(i<s.length()&&s[i]==' ')i++;
            while(i<s.length()&&s[i]!=' ')i++;
            cnt++;    
        }
        return cnt;
    }
};