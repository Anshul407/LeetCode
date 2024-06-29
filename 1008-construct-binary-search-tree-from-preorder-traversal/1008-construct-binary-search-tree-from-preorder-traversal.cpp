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
    TreeNode* solve(vector<int>&v,int left,int right,int &i){
        if(i==v.size()){
            return NULL;
        }
        
        if (v[i] < left || v[i] > right) {
        return NULL;
    }
        
        TreeNode* root=new TreeNode(v[i]);
            
        int val=v[i];
        i++;
        root->left=solve(v,left,val,i);
        root->right=solve(v,val,right,i);

        return root;
        

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
       return solve(preorder,INT_MIN,INT_MAX,i);
    }
};