class Solution {
public:
    bool check(int i,int j,vector<vector<int>>&temp){
        int k=j;
        while(k>=0){
            if(temp[i][k])return 0;
            k--;
        }
        int ii=i;
        k=j;
        while(ii>=0&&k>=0){
            if(temp[ii][k])return 0;
            ii--,k--;
        }
        ii=i;
        k=j;
        while(k>=0&&ii<temp.size()){
            if(temp[ii][k])return 0;
            ii++,k--;
        }return 1;
    }
    int solve(int i,vector<vector<int>>&temp){
        if(i>=temp.size())return 1;
        int ans=0;
        for(int j=0;j<temp.size();j++){
            if(check(j,i,temp)){
                temp[j][i]=1;
                ans+=solve(i+1,temp);
                temp[j][i]=0;
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        int ans=0;
        
        vector<vector<int>>temp(n,vector<int>(n,0));
        ans+=solve(0,temp);
        return ans;
    }
};