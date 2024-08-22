class Solution {
public:
    int solve(string s, int i, vector<int> temp, map<string, int> mp, vector<int> &dp, vector<vector<int>> &ans) {
        if (i >= s.length()) {
            ans.push_back(temp);
            return 1;
        }
        

        int ansa = 0;
        string x = "";
        for (int j = i; j < s.size(); j++) {
            x += s[j];
            if (mp.find(x) != mp.end()) {
                temp.push_back(mp[x]);
                ansa = max(ansa, solve(s, j + 1, temp, mp, dp, ans));
                temp.pop_back();
            }
        }
        return dp[i] = ansa;
    }

    vector<string> wordBreak(string s, vector<string> &wordDict) {
        vector<int> dp(s.length(), -1);
        map<string, int> mp;
        for (int i = 0; i < wordDict.size(); i++) {
            mp[wordDict[i]] = i;
        }

        vector<int> temp;
        vector<vector<int>> ans;
        solve(s, 0, temp, mp, dp, ans);

        vector<string> ap;
        for (auto v : ans) {
            string result = "";
            for (auto j : v) {
                result += wordDict[j] + " ";
            }
            result.pop_back();  // Remove the trailing space
            ap.push_back(result);
        }
        return ap;
    }
};
