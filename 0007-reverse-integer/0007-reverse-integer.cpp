class Solution {
public:
    void rev(string &t) {
        int i = 0, j = t.size() - 1;
        while (i < j) {
            swap(t[i], t[j]);
            i++;
            j--;
        }
    }

    int reverse(int x) {
        
        if (x == INT_MIN) {
            return 0;
        }
        int f = 0;
        if (x < 0) {
            f = 1;
            x = -x;
        }
        string temp = to_string(x);
        rev(temp);
        long long ans = stoll(temp);
        if (f) {
            ans = -ans;
        }
        if (ans > INT_MAX || ans < INT_MIN) {
            return 0;
        }
        return ans;
    }
};
