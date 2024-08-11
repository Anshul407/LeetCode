class Solution {
public:
    const int MOD = 1e9+7;
    int solve(vector<string>&words,string t,int i,int j,vector<vector<int>>&dp, vector<vector<long long>>&freq){
        if (i == t.length()) return 1;
        if (j >= words[0].size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int tk = 0, ntk = 0;
        
            tk = (freq[t[i]-'a'][j] * solve(words, t, i + 1, j + 1, dp,freq)) % MOD;
        
        ntk = solve(words, t, i, j + 1, dp,freq) % MOD;

        return dp[i][j] = (tk + ntk) % MOD;
    }
    int numWays(vector<string>& words, string &target) {
         int m = target.size(), n = words[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        vector<vector<long long>> freq(26, vector<long long>(words[0].size()));
        for(int col = 0; col < words[0].length(); col++) {
            for(string &word : words) {
                
                freq[word[col] - 'a'][col]++;  
            }
            
        }
        return solve(words,target,0,0,dp,freq);


    }
};