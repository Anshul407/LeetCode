class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        map<int,int>row,col;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(row[i]==1&&col[j]==1&&mat[i][j])ans++;
            }
        }return ans;
    }
};