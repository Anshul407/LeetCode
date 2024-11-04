class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        for(auto i:words){
            if(i[0]==pref[0]){
                if(i.substr(0,pref.size())==pref)cnt++;
            }
        }
        return cnt;
    }
};