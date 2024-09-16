class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> mp;
        for (auto i : s) mp[i]++;
        vector<pair<int, char>> v;
        int n = s.size();
        
        for (auto i : mp) {
            if (i.second > (n + 1) / 2) return "";
            v.push_back({i.second, i.first});
        }
        sort(v.rbegin(), v.rend());

        string ans = s;
        int idx = 0;

        for (auto& [freq, ch] : v) {
            while (freq--) {
                ans[idx] = ch;
                idx += 2;
                if (idx >= n) idx = 1;  
            }
        }
        
        return ans;
    }
};
