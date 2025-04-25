class Solution {
public:
    int can(vector<vector<int>>& matrix,int mid){
        int cur=0;
        int i=matrix.size()-1;
        int j=0;
        while(i>=0&&j<matrix.size()){
            if(matrix[i][j]>mid)i--;
            else {
                cur+=(i+1);
                j++;
            }
        }return cur;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int i=matrix[0][0];
        int j=matrix[matrix.size()-1][matrix.size()-1];
        while(i<j){
            auto mid=i+(j-i)/2;
            if(can(matrix,mid)<k)i=mid+1;
            else j=mid;
        }return i;
    }
};