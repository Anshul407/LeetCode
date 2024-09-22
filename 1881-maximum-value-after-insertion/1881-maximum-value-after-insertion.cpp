class Solution {
public:
    string maxValue(string n, int x) {
        if (n[0] == '-') {
            for (int i = 1; i < n.size(); ++i) {
                if (x < (n[i] - '0')) {
                    return n.substr(0, i) + to_string(x) + n.substr(i);
                }
            }
            return n + to_string(x);  
        }

        for (int i = 0; i < n.size(); ++i) {
            if (x > (n[i] - '0')) {
                return n.substr(0, i) + to_string(x) + n.substr(i);
            }
        }
        return n + to_string(x); 
    }
};
