class Solution {
public:
    
    int minimumOperationsToMakeEqual(int x, int y) {
        queue<pair<int,int>>q;
        q.push({x,0});
        unordered_set<int>vis;
        vis.insert(x);
        while(!q.empty()){
            auto node=q.front().first;
            auto w=q.front().second;
            q.pop();
            if(node==y)return w;
            if(node%11==0&&vis.find(node/11)==vis.end()){
                q.push({node/11,w+1});
                vis.insert(node/11);
            }
            if(node%5==0&&vis.find(node/5)==vis.end()){
                q.push({node/5,w+1});
                vis.insert(node/5);
            }
            if(vis.find(node-1)==vis.end()){
                q.push({node-1,w+1});
                vis.insert(node-1);
            }
            if(vis.find(node+1)==vis.end()){
                q.push({node+1,w+1});
                vis.insert(node+1);
            }
        }
        return -1;
    }
};