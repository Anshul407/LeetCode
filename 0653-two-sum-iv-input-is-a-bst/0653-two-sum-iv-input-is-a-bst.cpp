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
     unordered_set<int> st;
    bool findTarget(TreeNode* root, int k) {
              if(root==NULL)return 0;

              int val=root->val;
bool left=findTarget(root->left,k);

              if(left)return 1;
              if(st.find(k-val)!=st.end())return 1;

              
              st.insert(root->val);


             
                bool right =findTarget(root->right,k);
            if(right)return 1;
              

              return 0;
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

    }
};