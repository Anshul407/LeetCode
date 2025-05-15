class Solution {
public:
    int solve(vector<int>& cur) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i <= cur.size(); i++) {
            while (!st.empty() && (i == cur.size() || cur[st.top()] >= (i == cur.size() ? 0 : cur[i]))) {
                int height = cur[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, width * height);
            }
            st.push(i);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int ans = 0;
        int n = matrix.size(), m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            vector<int> cur(m, 0);
            for (int j = 0; j < m; j++) {
                int k = i, cnt = 0;
                while (k >= 0) {
                    if (matrix[k][j] == '0') break;
                    cnt++;
                    k--;
                }
                cur[j] = cnt;
            }
            ans = max(ans, solve(cur));
        }
        return ans;
    }
};
