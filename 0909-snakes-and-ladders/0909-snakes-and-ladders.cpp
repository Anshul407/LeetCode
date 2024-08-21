class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<pair<int, int>> q;
        int flag = 1;
        int s = board[0].size();
        vector<vector<int>> m(board.size(), vector<int>(s, 0));
        int cnt = 1;
        
       
        for (int i = board.size() - 1; i >= 0; i--) {
            if (flag) {
                for (int j = 0; j < s; j++) {
                    m[i][j] = cnt;
                    cnt++;
                }
                flag = 0;
            } else {
                for (int j = s - 1; j >= 0; j--) {
                    m[i][j] = cnt;
                    cnt++;
                }
                flag = 1;
            }
        }
        
        
        unordered_map<int, int> mp;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < s; j++) {
                if (board[i][j] != -1)
                    mp[m[i][j]] = board[i][j];
                else
                    mp[m[i][j]] = m[i][j];
            }
        }
        
        q.push({1, 0});
        vector<int> vis(board.size() * s + 1, 0);
        vis[1] = 1;
        
        while (!q.empty()) {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            if (node == s * board.size()) return dist;
            
            for (int i = 1; i <= 6; i++) {
                int next = node + i;
                if (next <= s * board.size() && !vis[mp[next]]) {
                    q.push({mp[next], dist + 1});
                    vis[mp[next]] = 1;
                }
            }
        }
        
        return -1;
    }
};
