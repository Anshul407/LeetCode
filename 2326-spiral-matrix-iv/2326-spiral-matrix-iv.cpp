class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        
        int up = 0, down = m - 1, left = 0, right = n - 1;
        while (head) {
            // Fill from left to right
            for (int x = left; x <= right; ++x) {
                if (!head) return ans;
                ans[up][x] = head->val;
                head = head->next;
            }
            ++up;
            if (up > down) break;

            // Fill from top to bottom
            for (int x = up; x <= down; ++x) {
                if (!head) return ans;
                ans[x][right] = head->val;
                head = head->next;
            }
            --right;
            if (left > right) break;

            // Fill from right to left
            for (int x = right; x >= left; --x) {
                if (!head) return ans;
                ans[down][x] = head->val;
                head = head->next;
            }
            --down;
            if (up > down) break;

            // Fill from bottom to top
            for (int x = down; x >= up; --x) {
                if (!head) return ans;
                ans[x][left] = head->val;
                head = head->next;
            }
            ++left;
            if (left > right) break;
        }
        return ans;
    }
};
