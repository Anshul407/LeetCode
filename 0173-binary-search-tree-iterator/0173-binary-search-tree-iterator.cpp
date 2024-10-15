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
class BSTIterator {
public:
   queue<int>st;
    void solve(queue<int>&st,TreeNode*root){
        if(!root)return ;
        solve(st,root->left);
        st.push(root->val);
        solve(st,root->right);
    }
    BSTIterator(TreeNode* root) {
        solve(st,root);
    }
    
    int next() {
        if(st.size()){
            int x=st.front();
            st.pop();
            return x;
        }
        return 0;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */