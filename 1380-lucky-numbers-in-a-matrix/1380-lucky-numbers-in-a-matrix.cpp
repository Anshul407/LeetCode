class Solution {
public:
    bool mp(vector<vector<int>>& matrix,int i,int j,int val){
        for(int x=0;x<matrix.size();x++){
            if(matrix[x][j]>val&&(x!=i))return false;
        }
        for(int x=0;x<matrix[0].size();x++){
            if(matrix[i][x]<val&&(x!=j))return false;
        }
        return true;
    }
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>ans;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int val=matrix[i][j];
                if(mp(matrix,i,j,val))ans.push_back(matrix[i][j]);
                
            }
        }
        return ans;
    }
};