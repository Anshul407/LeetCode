class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(auto i:strs){
            string c=i;
            sort(i.begin(),i.end());
            mp[i].push_back(c);
        }
        vector<vector<string>>ans;
        for(auto v:mp){
            ans.push_back(v.second);
        }
        return ans;

    }
};