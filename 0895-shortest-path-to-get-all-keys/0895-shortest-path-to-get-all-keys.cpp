class Solution {
public:

    int shortestPathAllKeys(vector<string>& grid) {
        int x=0;
        for(auto i:grid){
            for(auto j:i){
                if(islower(j))x++;
            }
        }
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='@'){
                    q.push({0,{i,j}});
                    break;
                }
            }
        }
        int keys=(1<<x);
        
        vector<vector<vector<int>>>dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(keys,0)));

        int ans=0;
        map<char,int>mp;
        while(!q.empty()){
            auto size=q.size();
            
            for(int l=0;l<size;l++){
                auto xx=q.front();
                q.pop();
                auto key=xx.first;
                auto i=xx.second.first;
                auto j=xx.second.second;
                

                if(i<0||j<0||i>=grid.size()||j>=grid[0].size())continue;
               
                if(grid[i][j]=='#')continue;
                auto cur=grid[i][j];
                if(isupper(grid[i][j])&&!(key&(1<<(cur-'A')))){
                   continue;
                }
                int newkey=key;
                if(islower(grid[i][j])){
                    newkey|=1<<(cur-'a');
                }
                if(newkey==(1<<x)-1)return ans;
                if(dp[i][j][newkey]==1)continue;
                else dp[i][j][newkey]=1;
                q.push({newkey,{i-1,j}});
                q.push({newkey,{i,j-1}});
                q.push({newkey,{i+1,j}});
                q.push({newkey,{i,j+1}});
            }
            ans++;
            
        }
        return -1;
    }
};