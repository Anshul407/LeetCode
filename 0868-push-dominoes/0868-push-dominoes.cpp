class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<pair<int, char>> positions;
        int n = dominoes.size();
        for (int i = 0; i < n; i++) {
            if (dominoes[i] != '.')
                positions.push_back({i, dominoes[i]});
        }
        while (!positions.empty()) {
            vector<pair<int, char>> new_positions;
            for (auto pos: positions) {
                if (pos.second == 'L') {
                    if (pos.first == 0 || dominoes[pos.first-1] != '.') {
                        continue;
                    }
                    if (new_positions.size() > 0 && new_positions.back().first == pos.first - 1) {
                        new_positions.pop_back();
                    } else {
                        new_positions.push_back({pos.first - 1, pos.second});
                    }
                } else {
                    if (pos.first == n-1 || dominoes[pos.first + 1] != '.') {
                        continue;
                    }
                    new_positions.push_back({pos.first + 1, pos.second});
                }            
            }
            for (auto new_pos: new_positions) {
                dominoes[new_pos.first] = new_pos.second;
            }
            swap(positions, new_positions);
        }
        return dominoes;
    }
};