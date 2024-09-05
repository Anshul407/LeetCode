class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans=0;
        for(auto i:words){
            if(s.substr(0,i.length())==i)ans++;
        }
        return ans;
        }
};