class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            int flag = 0;
            for (int mm = 0; mm < size; mm++) {
                auto it = q.front();
                q.pop();
                int i = it.first;
                int j = it.second;

                if (i > 0) {
                    int up = i - 1;
                    if (grid[up][j] == 1) {
                        q.push({up, j});
                        grid[up][j] = 0;
                        flag = 1;
                    }
                }
                if (j > 0) {
                    int up = j - 1;
                    if (grid[i][up] == 1) {
                        q.push({i, up});
                        grid[i][up] = 0;
                        flag = 1;
                    }
                }
                if (i < n - 1) {
                    int up = i + 1;
                    if (grid[up][j] == 1) {
                        q.push({up, j});
                        grid[up][j] = 0;
                        flag = 1;
                    }
                }
                if (j < m - 1) {
                    int up = j + 1;
                    if (grid[i][up] == 1) {
                        q.push({i, up});
                        grid[i][up] = 0;
                        flag = 1;
                    }
                }
            }
              if (flag)
            ans++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;

      
    }
    
};