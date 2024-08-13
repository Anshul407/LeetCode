class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int i=0;
        while(i<matrix[0].size()){
            int j=0,p=i;
            int num=matrix[j][p];
            while(j<matrix.size()&&p<matrix[0].size()){
                if(num!=matrix[j][p])return 0;
                j++;
                p++;
            }
            i++;
        }
        i = 1;
        while (i < matrix.size()) {
            int j = i, p = 0;
            int num = matrix[j][p];
            while (j < matrix.size() && p < matrix[0].size()) {
                if (num != matrix[j][p]) return false;
                j++;
                p++;
            }
            i++;
        }
        return 1;
    }
};