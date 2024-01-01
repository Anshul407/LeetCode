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
  TreeNode*solve(vector<int>& inorder,vector<int>& preorder,int pres,int prend,int &index,map<int,int>&mp){
      if(index>=preorder.size()||pres>prend)return NULL;
    int elem=preorder[index++];
      TreeNode*root=new TreeNode(elem);
      int pos=mp[elem];
      root->left=solve(inorder,preorder,pres,pos-1,index,mp);
      root->right=solve(inorder,preorder,pos+1,prend,index,mp);

      return root;
  }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder(preorder);
        sort(inorder.begin(),inorder.end());
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int pres=0;
        int prend=inorder.size()-1;
        int index=0;
        return solve(inorder,preorder,pres,prend,index,mp);
    }
};