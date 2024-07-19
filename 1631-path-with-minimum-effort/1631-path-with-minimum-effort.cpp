class Solution {
public:
    vector<vector<int>> direction = {
        {1, 0},   // down
        {-1, 0},  // up
        {0, 1},   // right
        {0, -1},  // left
        {1, 1},   // down-right
        {1, -1},  // down-left
        {-1, 1},  // up-right
        {-1, -1}  // up-left
    };

    bool issafe(int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        typedef pair<int, pair<int, int>> P; 
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, {0, 0}});
        res[0][0] = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int dist = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if (x == n - 1 && y == m - 1) {
                return dist;
            }

            for (auto dir : direction) {
                int newx = x + dir[0];
                int newy = y + dir[1];

                if (issafe(newx, newy, n, m)) {
                    int newDiff = max(dist, abs(heights[x][y] - heights[newx][newy]));
                    if (newDiff < res[newx][newy]) {
                        res[newx][newy] = newDiff;
                        pq.push({newDiff, {newx, newy}});
                    }
                }
            }
        }

        return res[n - 1][m - 1];
    }
};
