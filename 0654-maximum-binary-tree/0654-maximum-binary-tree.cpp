/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(int start,int end,vector<int>nums){
        if(start>=end)return NULL;
        int maxi = INT_MIN;
        int ind = -1;
        for (int i = start; i < end; ++i) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                ind = i;
            }
        }
        TreeNode* ans=new TreeNode(nums[ind]);
        ans->left=solve(start,ind,nums);
        ans->right=solve(ind+1,end,nums);

        return ans;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       
        return solve(0,nums.size(),nums);

        
    }
};