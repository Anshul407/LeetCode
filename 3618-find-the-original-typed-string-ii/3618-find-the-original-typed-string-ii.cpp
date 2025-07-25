class Solution {  
public:
const int MOD = 1e9+7;
    int possibleStringCount(string word, int k) {
        vector<int> groups;
        for(int i = 0, n = word.size(); i < n; ) {
            int j = i+1;
            while(j<n && word[j]==word[i]) j++;
            groups.push_back(j - i);
            i = j;
        }

        long long total = 1;
        for(int g : groups)
            total = total * g % MOD;

        int m = groups.size();
        if(k > (int)groups.size()) {
            vector<int> dp(k), newdp(k);
            dp[0] = 1;
            for(int idx = 0; idx < m; idx++) {
                int len = groups[idx];
                fill(newdp.begin(), newdp.end(), 0);

                long long window = 0;
                for(int j = 1; j < k; j++) {
                    window = (window + dp[j-1]) % MOD;
                    if(j - 1 - len >= 0)
                        window = (window - dp[j - 1 - len] + MOD) % MOD;
                    newdp[j] = window;
                }
                dp.swap(newdp);
            }

            long long invalid = 0;
            for(int j = 1; j < k; j++)
                invalid = (invalid + dp[j]) % MOD;

            return int((total - invalid + MOD) % MOD);
        }
        return int(total);
    }
};