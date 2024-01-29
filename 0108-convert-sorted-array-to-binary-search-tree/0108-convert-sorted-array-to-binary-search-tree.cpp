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
    TreeNode* mp(vector<int>nums,int i,int j){
        if(i>j){
            return NULL;
        }
        else{
            int mid=(i+j)/2;
            TreeNode* x=new TreeNode(nums[mid]);

            x->left=mp(nums,i,mid-1);
            x->right=mp(nums,mid+1,j);

            return x;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return mp(nums,0,nums.size()-1);
    }
};