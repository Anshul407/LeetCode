/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node*node,Node*clone,map<Node*,Node*>&mp){
        for(auto v:node->neighbors){
            if(mp.find(v)==mp.end()){
                Node* cl=new Node(v->val);
                mp[v]=cl;
                clone->neighbors.push_back(cl);
                dfs(v,cl,mp);
            }else{
                clone->neighbors.push_back(mp[v]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        map<Node*,Node*>mp;
        Node* clone=new Node(node->val);
        mp[node]=clone;
        dfs(node,clone,mp);
        return clone;
    }
};