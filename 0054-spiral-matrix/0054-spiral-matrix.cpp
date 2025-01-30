class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i=0,j=0;
        int s1=matrix.size()-1;
        int s2=matrix[0].size()-1;
        int cur=0;
        int f=0;
        vector<int>ans;
        while(i<=s1&&j<=s2){
            f=0;
            for(int k=j;k<=s2;k++){
                ans.push_back(matrix[i][k]);
                f=1;
            }
            i++;
            for(int k=i;k<=s1;k++){
                ans.push_back(matrix[k][s2]);
                f=1;
            }
            s2--;
            if(i<=s1){
            for(int k=s2;k>=j;k--){
                ans.push_back(matrix[s1][k]);
                f=1;
            }s1--;
            }
            if(j<=s2){
            for(int k=s1;k>=i;k--){
                ans.push_back(matrix[k][j]);
                f=1;
            }j++;}
        }return ans;
    }
};