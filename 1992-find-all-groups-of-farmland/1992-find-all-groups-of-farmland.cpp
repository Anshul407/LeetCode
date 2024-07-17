class Solution {
public:
   void dfs(vector<vector<int>>& land,int i,int j,int &a,int &b){
        land[i][j]=0;
        if(i>=a&&j>=b){
            a=i;
            b=j;
        }
        if(i!=0){
            int up=i-1;
            if(land[up][j]==1){
                dfs(land,up,j,a,b);
            }
        }
        if(j!=0){
            int up=j-1;
            if(land[i][up]==1){
                dfs(land,i,up,a,b);
            }
        }
        if(i<land.size()-1){
            int up=i+1;
            if(land[up][j]==1){
                dfs(land,up,j,a,b);
            }
        }
        if(j<land.size()-1){
            int up=j+1;
            if(land[i][up]==1){
                dfs(land,i,up,a,b);
            }
        }
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[0].size();j++){
                if(land[i][j]==1){
                    int a=-1,b=-1;
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    dfs(land,i,j,a,b);
                    
                    temp.push_back(a);
                    temp.push_back(b);
                    ans.push_back(temp);
                    cout<<"cc";
                }
                
            }
        }
        return ans;
    }
};