class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans="";
        vector<pair<char,int>>v;
        for(int i=0;i<s.length();i++){
            v.emplace_back(indices[i],s[i]);
        }
        sort(v.begin(),v.end());
        for(auto i:v){
            ans.push_back(i.second);
        }
        return ans;
    }
};