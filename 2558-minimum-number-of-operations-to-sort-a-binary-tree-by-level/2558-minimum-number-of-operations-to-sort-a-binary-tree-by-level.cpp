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
    int f(vector<int>&a,int k){
        for(int i=0;i<a.size();i++){
            if(a[i]==k)return i;
        }
        return -1;
    }
    int solve(vector<int>&t){
        map<int,int>mp;
        vector<int>arr=t;
        int ans=0;
        sort(t.begin(),t.end());
        
        for(int i=0;i<t.size();i++){
            if(arr[i]!=t[i]){
                int key=f(arr,t[i]);
                swap(arr[i],arr[key]);
                ans++;
            }
        }
        return ans;

    }
    int minimumOperations(TreeNode* root) {
        if(!root)return 0;
        int ans=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto s=q.size();
            vector<int>temp;
            for(int i=0;i<s;i++){
                auto v=q.front();
                q.pop();
                
                if(v->left){
                    temp.push_back(v->left->val);
                    q.push(v->left);
                }
                if(v->right){
                    temp.push_back(v->right->val);
                    q.push(v->right);
                }

                
            }
            if(!temp.empty())
            ans+=solve(temp);
        }
        return ans;
    }
};