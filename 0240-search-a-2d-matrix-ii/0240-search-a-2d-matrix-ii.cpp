class Solution {
public:
    bool bs(vector<vector<int>>& matrix,int i,int j,int n,int t){
       
        if(j<=n){
            int mid=(j+n)/2;

            if(matrix[i][mid]==t)return 1;

           if (matrix[i][mid] > t) {
                return bs(matrix, i, j, mid - 1, t); 
            } else {
                return bs(matrix, i, mid + 1, n, t); 
            }

        }
        return 0;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
           if( bs(matrix,i,0,matrix[i].size()-1,target))return 1;
        }
        return 0;
    }
};