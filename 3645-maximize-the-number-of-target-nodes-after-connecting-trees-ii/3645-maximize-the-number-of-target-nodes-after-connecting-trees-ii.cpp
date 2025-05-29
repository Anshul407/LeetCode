class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> tree1(n);
        for (vector<int>& e : edges1) {
            tree1[e[0]].push_back(e[1]);
            tree1[e[1]].push_back(e[0]);
        }

        vector<vector<int>> tree2(m);
        for (vector<int>& e : edges2) {
            tree2[e[0]].push_back(e[1]);
            tree2[e[1]].push_back(e[0]);
        }

        vector<int> dist1(n, -1);
        queue<int> ueue;
        dist1[0] = 0;
        ueue.push(0);
        while (!ueue.empty()) {
            int node = ueue.front();
            ueue.pop();

            for (int neighbor : tree1[node]) {
                if (dist1[neighbor] == -1) {
                    dist1[neighbor] = dist1[node] + 1;
                    ueue.push(neighbor);
                }
            }
        }

        int evens1 = 0, odds1 = 0;
        for (int i = 0; i < dist1.size(); i++) {
            ((dist1[i] % 2) ? odds1 : evens1)++;
        }

        vector<int> dist2(m, -1);
        queue<int>().swap(ueue);
        dist2[0] = 0;
        ueue.push(0);
        while (!ueue.empty()) {
            int node = ueue.front();
            ueue.pop();

            for (int neighbor : tree2[node]) {
                if (dist2[neighbor] == -1) {
                    dist2[neighbor] = dist2[node] + 1;
                    ueue.push(neighbor);
                }
            }
        }

        int evens2 = 0, odds2 = 0, adds2 = 0;
        for (int i = 0; i < dist2.size(); i++) {
            ((dist2[i] % 2) ? odds2 : evens2)++;
        }

        adds2 = max(evens2, odds2);

        vector<int> res;
        res.reserve(n);

        for (int i = 0; i < n; i++) {
            res.push_back(((dist1[i] % 2) ? odds1 : evens1) + adds2);
        }

        return res;
    }
};