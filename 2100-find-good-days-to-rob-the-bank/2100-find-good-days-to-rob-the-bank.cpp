class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> ans;

        if (time == 0) {
            for (int i = 0; i < n; i++) {
                ans.push_back(i);
            }
            return ans;
        }

        for (int i = time; i < n - time; i++) {
            bool valid = true;

            
            for (int j = i - time; j < i; j++) {
                if (security[j] < security[j + 1]) {
                    valid = false;
                    break;
                }
            }

            
            for (int j = i; j < i + time; j++) {
                if (security[j] > security[j + 1]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
