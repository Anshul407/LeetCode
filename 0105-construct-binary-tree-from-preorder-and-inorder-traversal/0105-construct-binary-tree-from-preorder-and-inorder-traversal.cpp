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
    TreeNode*mpp(vector<int>& preorder, vector<int>& inorder,int prest,int preend,map<int,int>&mp,int &index){

        if(index>=preorder.size()||prest>preend)return NULL;

        int elem=preorder[index++];
        TreeNode*root=new TreeNode(elem);
        int pos=mp[elem];
        root->left=mpp(preorder,inorder,prest,pos-1,mp,index);
        root->right=mpp(preorder,inorder,pos+1,preend,mp,index);

        return root;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int prest=0;
        int preend=inorder.size()-1;
        int index=0;
        return mpp(preorder,inorder,prest,preend,mp,index);
    }
};