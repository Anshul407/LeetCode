class Solution {
public:
    vector<int>dp;
    bool solve(string &s,int i,unordered_map<string,int>&mp){
        if(i>=s.size())return 1;
        if(dp[i]!=-1)return dp[i];
        string cur="";
        for(int j=i;j<s.size();j++){
            cur+=s[j];
            if(mp[cur]){
                if(solve(s,j+1,mp))return 1;
            }
        }return dp[i]= 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.size(),-1);
        unordered_map<string,int>mp;
        for(auto &i:wordDict)mp[i]++;
        return solve(s,0,mp);
    }
};