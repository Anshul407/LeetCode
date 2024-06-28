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
    bool isEvenOddTree(TreeNode* root) {
        if(!root)return 1;
        int ans=1;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            int flag = (q.front().second % 2 == 0) ? INT_MIN : INT_MAX;
            // int level=q.front().second;
            for(int i=0;i<size;i++){
                 
                 auto it=q.front();
                 q.pop();
                 int level=it.second;
                 auto Node=it.first;
                 cout<<flag<<" ";
                  if(level%2==0){
                      
                      if(Node->val%2==0||Node->val<=flag){
                            ans=0;
                            break;
                      } 
                  }else{
                       if(Node->val%2!=0||Node->val>=flag){
                            ans=0;
                            break;
                       }
                  }
                  flag=Node->val;
                 if(!ans)break;
                  if(Node->left)q.push({Node->left,level+1});
                  if(Node->right)q.push({Node->right,level+1});
            }
            cout<<endl;
        }
        return ans;
    }
};