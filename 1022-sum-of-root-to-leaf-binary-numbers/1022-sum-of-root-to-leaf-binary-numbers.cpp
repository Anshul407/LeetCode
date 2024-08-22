/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int dec(int n) {
        int num = n;
        int dec_value = 0;

        int base = 1;

        int temp = num;
        while (temp) {
            int last_digit = temp % 10;
            temp = temp / 10;

            dec_value += last_digit * base;

            base = base * 2;
        }

        return dec_value;
    }

    void solve(TreeNode* root, int& ans, int num, int p) {
        if (root == NULL)
            return;
        num = (num * 10) + root->val;
        if (!root->left && !root->right) {
            ans += dec(num);
            return;
        }
        solve(root->left, ans, num, p - 1);
        solve(root->right, ans, num, p - 1);
    }

    int sumRootToLeaf(TreeNode* root) {
        int hh = 0;
        int ans = 0;
        int num = 0;
        solve(root, ans, num, hh);
        return ans;
    }
};