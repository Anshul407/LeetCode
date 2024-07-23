class Solution {
public:
    static bool cmp(pair<int,int>p, pair<int,int>q) {
        return p.first < q.first;
    }

    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> v;
        for (int i = 0; i <= n; i++) {
            v.push_back({i - ranges[i], i + ranges[i]});
        }
        sort(v.begin(), v.end(), cmp);

        int taps = 0;
        int end = 0, farthest = 0;
        int i = 0;
        
        while (end < n) {
            while (i < v.size() && v[i].first <= end) {
                farthest = max(farthest, v[i].second);
                i++;
            }
            if (end == farthest) {
                return -1; 
            }
            end = farthest;
            taps++;
        }

        return taps;
    }
};
