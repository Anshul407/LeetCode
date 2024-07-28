class Solution {
public:
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++){
            vector<int>temp;
            for(int j=0;j<=i;j++){
                temp.push_back(0);
            }
            ans.push_back(temp);
        }
        for(int i=0;i<numRows;i++){
            ans[i][0]=1;
            ans[i][i]=1;
        }
        for(int i=2;i<numRows;i++){
            
            for(int j=1;j<i;j++){
               ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
            }
           
        }
        return ans;

        
    }
};