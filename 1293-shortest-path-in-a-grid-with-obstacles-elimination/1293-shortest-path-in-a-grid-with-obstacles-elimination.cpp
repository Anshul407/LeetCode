class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
       
        if (k >= m + n - 2) return m + n - 2;

        queue<pair<pair<int, int>, pair<int, int>>> q;
        q.push({{0, 0}, {0, 0}});
        vector<vector<int>> vis(m, vector<int>(n, INT_MAX));  

        vis[0][0] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int i = it.first.first;
            int j = it.first.second;
            int dist = it.second.first;
            int kk = it.second.second;

            if (i == m - 1 && j == n - 1) {
                return dist;
            }

           
            int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

            for (auto& dir : dirs) {
                int ni = i + dir[0];
                int nj = j + dir[1];

                if (ni >= 0 && nj >= 0 && ni < m && nj < n) {
                    int newK = kk + grid[ni][nj];
                    if (newK <= k && newK < vis[ni][nj]) {
                        vis[ni][nj] = newK;
                        q.push({{ni, nj}, {dist + 1, newK}});
                    }
                }
            }
        }

        return -1;  // If no path is found
    }
};
