class Solution {
public:
    string makeGood(string s) {
        string ans="";
        ans.push_back(s[0]);
        for(int i=1;i<s.length();i++){
            if (!ans.empty() && 
           ((tolower(s[i]) == tolower(ans.back()) && s[i] != ans.back()))) {
            ans.pop_back();
        } else {
            ans.push_back(s[i]);
        }
        }
        return ans;
    }
};