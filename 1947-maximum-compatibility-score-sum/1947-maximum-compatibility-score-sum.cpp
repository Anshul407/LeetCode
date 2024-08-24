class Solution {
public:
    int solve(vector<vector<int>>& students, vector<vector<int>>& mentors, int i, vector<vector<int>>& vis) {
        if(i == students.size()) return 0;
        int maxi = INT_MIN;
        for(int j = 0; j < students.size(); j++) {
            if(vis[0][j] == 0) {
                int cnt = 0;
                for(int x = 0; x < mentors[0].size(); x++) {
                    if(students[i][x] == mentors[j][x]) cnt++;
                }
                vis[0][j] = 1;
                maxi = max(maxi, cnt + solve(students, mentors, i + 1, vis));
                vis[0][j] = 0;
            }
        }
        return maxi;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<vector<int>> vis(students.size(), vector<int>(students.size(), 0));
        return solve(students, mentors, 0, vis);
    }
};
