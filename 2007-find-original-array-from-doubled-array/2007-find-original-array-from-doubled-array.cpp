class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int> mp;
        for (auto i : changed) mp[i]++;
        vector<int> ans;

        sort(changed.begin(), changed.end());

        for (auto i : changed) {
            if (i == 0) {
                if (mp[i] % 2 != 0) return {}; 
                while (mp[i] > 0) {
                    ans.push_back(0); 
                    mp[i] -= 2; 
                }
            } 
            else if (mp[i] > 0 && mp.find(i * 2) != mp.end() && mp[i * 2] > 0) {
              
                ans.push_back(i);
                mp[i]--;
                mp[i * 2]--;
            }
        }

        for (auto& pair : mp) {
            if (pair.second > 0) return {};
        }

        return ans;
    }
};
