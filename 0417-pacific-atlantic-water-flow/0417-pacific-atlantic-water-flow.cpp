class Solution {
public:
    void solve(vector<vector<int>>&heights,int i,int j,vector<vector<int>>&cur,int p){
        if(i<0||j<0||i>=cur.size()||j>=cur[0].size()||heights[i][j]<p||cur[i][j])return ;
        cur[i][j]=1;
        
        solve(heights,i+1,j,cur,heights[i][j]);
        solve(heights,i-1,j,cur,heights[i][j]);
        solve(heights,i,j+1,cur,heights[i][j]);
        solve(heights,i,j-1,cur,heights[i][j]);
       
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>pacific(heights.size(),vector<int>(heights[0].size(),0));
        vector<vector<int>>atlantic(heights.size(),vector<int>(heights[0].size(),0));
        vector<vector<int>>ans;
        for(int i=0;i<heights.size();i++){
            solve(heights,i,0,pacific,INT_MIN);
            solve(heights,i,heights[0].size()-1,atlantic,INT_MIN);
        }
        for(int i=0;i<heights[0].size();i++){
            solve(heights,0,i,pacific,INT_MIN);
            solve(heights,heights.size()-1,i,atlantic,INT_MIN);
        }
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(pacific[i][j]&&atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};