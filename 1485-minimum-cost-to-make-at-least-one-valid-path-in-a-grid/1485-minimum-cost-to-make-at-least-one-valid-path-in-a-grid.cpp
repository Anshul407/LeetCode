class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        map<pair<int,int>,int>vis;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        while(!q.empty()){
            auto cur=q.top();
            q.pop();
            auto d=cur.first;
            auto i=cur.second.first;
            auto j=cur.second.second;
            if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||vis[{i,j}]==1)continue;
            if(i==grid.size()-1&&j==grid[0].size()-1)return d;
            auto dir=grid[i][j];
            vis[{i,j}]=1;
            if(dir==1){
                q.push({d+1,{i+1,j}});
                q.push({d+1,{i-1,j}});
                q.push({d,{i,j+1}});
                q.push({d+1,{i,j-1}});
            }else if(dir==2){
                q.push({d+1,{i+1,j}});
                q.push({d+1,{i-1,j}});
                q.push({d+1,{i,j+1}});
                q.push({d,{i,j-1}});
            }else if(dir==3){
                q.push({d,{i+1,j}});
                q.push({d+1,{i-1,j}});
                q.push({d+1,{i,j+1}});
                q.push({d+1,{i,j-1}});
            }else {
                q.push({d+1,{i+1,j}});
                q.push({d,{i-1,j}});
                q.push({d+1,{i,j+1}});
                q.push({d+1,{i,j-1}});
            }
        }
        return -1;
    }
};