class Solution {
public:
    int partitionString(string s) {
        map<int,int>mp;
        int cnt=1;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])!=mp.end()){
                cnt++;
                mp.clear();
            }
            mp[s[i]]++;
        }
        return cnt;
    }
};