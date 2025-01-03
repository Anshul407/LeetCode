/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int,vector<int>>mp;
    int r;
    void f(TreeNode*root){
        if(!root)return ;

        if(root->left){
            mp[root->left->val].push_back(root->val);
            mp[root->val].push_back(root->left->val);
        }
        if(root->right){
            mp[root->right->val].push_back(root->val);
            mp[root->val].push_back(root->right->val);
        }
        f(root->left);
        f(root->right);
    }
    vector<int> bfs(int s,int h){
        queue<pair<int,int>>q;
        q.push({s,0});
        vector<int>ans;
        unordered_set<int>st;
        st.insert(s);
        while(!q.empty()){
            auto x=q.front();
            auto node=x.first;
            auto d=x.second;
            q.pop();
            if(d==h){
                ans.push_back(node);
                continue;
            }
            for(auto v:mp[node]){
                if(st.find(v)==st.end()){
                    st.insert(v);
                    q.push({v,d+1});
                }
            }
        }
        return ans;

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        f(root);
        r=root->val;
        return bfs(target->val,k);

    }
};