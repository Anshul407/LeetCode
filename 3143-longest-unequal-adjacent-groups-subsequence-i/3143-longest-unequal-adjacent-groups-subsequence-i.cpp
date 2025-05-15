class Solution {
public:
    vector<string>solve(vector<string>& words,int i,int prev,vector<int>& groups,  map<string,vector<string>>&mp){
        if(i>=words.size())return {};

        if(mp.find(words[i])!=mp.end())return mp[words[i]];
        vector<string>temp,temp2;
        if(prev==-1||prev!=groups[i]){
            temp.push_back(words[i]);
            vector<string> next = solve(words, i + 1, groups[i], groups, mp);
            temp.insert(temp.end(), next.begin(), next.end());
        }
        temp2 = solve(words, i + 1, prev, groups, mp);

        if (temp.size() > temp2.size()) return mp[words[i]] = temp;
        return mp[words[i]] = temp2;
    }
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        map<string,vector<string>>mp;
       return  solve(words,0,-1,groups,mp);

    }
};