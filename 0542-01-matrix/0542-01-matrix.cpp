class Solution {
public:
    vector<vector<int>> vis;
    
    void solve(queue<pair<int,pair<int,int>>>& q, vector<vector<int>>& m, vector<vector<int>>& ans) {
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dist = it.first;
            int i = it.second.first;
            int j = it.second.second;
            
            if (ans[i][j] > dist) {
                ans[i][j] = dist;
            }
            
            if (i > 0 && !vis[i-1][j]) {
                q.push({dist+1, {i-1, j}});
                vis[i-1][j] = 1;
            }
            if (j > 0 && !vis[i][j-1]) {
                q.push({dist+1, {i, j-1}});
                vis[i][j-1] = 1;
            }
            if (i < m.size() - 1 && !vis[i+1][j]) {
                q.push({dist+1, {i+1, j}});
                vis[i+1][j] = 1;
            }
            if (j < m[0].size() - 1 && !vis[i][j+1]) {
                q.push({dist+1, {i, j+1}});
                vis[i][j+1] = 1;
            }
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,pair<int,int>>> q;
        vis.resize(mat.size(), vector<int>(mat[0].size(), 0));
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), INT_MAX));
        
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    q.push({0, {i, j}});
                    ans[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }
        
        solve(q, mat, ans);
        return ans;
    }
};
