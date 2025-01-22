class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,int>>q;
        for(int i=0;i<isWater.size();i++){
            for(int j=0;j<isWater[0].size();j++){
                if(isWater[i][j]==1){
                    isWater[i][j]=-1;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            auto i=node.first;
            auto j=node.second;
            int wt=0;
            if(isWater[i][j]==-1)wt=0;
            else wt=isWater[i][j];
            wt++;
            if(i-1>=0&&isWater[i-1][j]==0){
                isWater[i-1][j]=wt;
                q.push({i-1,j});
            }
            if(j-1>=0&&isWater[i][j-1]==0){
                isWater[i][j-1]=wt;
                q.push({i,j-1});
            }
            if(i+1<isWater.size()&&isWater[i+1][j]==0){
                isWater[i+1][j]=wt;
                q.push({i+1,j});
            }
            if(j+1<isWater[0].size()&&isWater[i][j+1]==0){
                isWater[i][j+1]=wt;
                q.push({i,j+1});
            }
        }
        for(int i=0;i<isWater.size();i++){
            for(int j=0;j<isWater[0].size();j++){
                if(isWater[i][j]==-1){
                    isWater[i][j]=0;
                }
            }
        }
        return isWater;
    }
};