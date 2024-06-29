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
    void inor(TreeNode*root,vector<int>&v){
        if(root==NULL)return ;

        inor(root->left,v);
        v.push_back(root->val);
        inor(root->right,v);
    }
    void insert(TreeNode*&root,int k){
        if(root==NULL){
            root=new TreeNode(k);
            return ;
        }

        if(root->val>k){
            insert(root->left,k);
        }
        else{
            insert(root->right,k);
        }

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        inor(root,v);
        TreeNode*temp=NULL;
        int mid=v.size()/2;
        for(int i=mid;i>=0;i--){
            insert(temp,v[i]);
        }
        for(int i=mid+1;i<v.size();i++){
             insert(temp,v[i]);
        }
        return temp;
        

    }
};