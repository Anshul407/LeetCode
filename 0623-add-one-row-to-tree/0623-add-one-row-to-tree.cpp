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
 
    void solve(TreeNode*root,int val,int depth,int cd){
        if(root==NULL)return ;
     
      
        if(depth-1==cd){
            if(root->left){
                TreeNode*temp=root->left;
             
                root->left=new TreeNode(val);
                
                root->left->left=temp;
            }
            if(root->right){
                TreeNode*temp=root->right;
              
                root->right=new TreeNode(val);;
                root->right->right=temp;
        }
        return ;

            
        }
        solve(root->left,val,depth,cd+1);
        solve(root->right,val,depth,cd+1);
        
       
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        solve(root,val,depth,1);
        return root;
    }
};