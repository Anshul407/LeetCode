class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        vector<vector<int>>ans;
        for(int j=0;j<matrix[0].size();j++){
            vector<int>temp;
            for(int i=0;i<matrix.size();i++){
                temp.push_back(matrix[i][j]);
            }
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                matrix[i][j]=ans[i][j];
            }
        }
        
    }
};