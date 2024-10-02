class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix[0].size()-1;
        int k=0;
        while(i<=j&&k<matrix.size()){
            int mid=(i+j)/2;
            if(matrix[k][mid]==target)return 1;
            else if(matrix[k][mid]>target){
                if(i==j){
                    k++;
                    i=0;
                    j=matrix[0].size()-1;
                }
                else j=mid-1;
            } else{
                if(i==j){
                    k++;
                    i=0;
                    j=matrix[0].size()-1;
                }
                else i=mid+1;

            }
        }
        return 0;
    }
};