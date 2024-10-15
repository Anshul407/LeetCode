class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            vector<int> mp(26, 0);
            for (int j = i; j < s.length(); j++) {
                mp[s[j] - 'a']++;  
                int maxi = 0, mini = INT_MAX;
                for (int x = 0; x < 26; x++) {
                    if (mp[x] > 0) {
                        maxi = max(maxi, mp[x]);
                        mini = min(mini, mp[x]);
                    }
                }
                ans += (maxi - mini);  
            }
        }
        return ans;
    }
};
