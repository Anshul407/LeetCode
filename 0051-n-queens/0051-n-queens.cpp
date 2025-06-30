class Solution {
public:
    bool check(int i,int j,vector<vector<int>>&t){
        int a=i;
        int b=j;
        while(j>=0){
            if(t[i][j]==1)return 0;
            j--;
        }
        j=b;
        while(i>=0&&j>=0){
            if(t[i][j]==1)return 0;
            j--;
            i--;
        }
        i=a,j=b;
        while(i<t.size()&&j>=0){
            if(t[i][j]==1)return 0;
            j--;
            i++;
        }return 1;
    }
    void help(vector<vector<string>>&ans,vector<vector<int>>&t){
        vector<string>cur;
        for(int i=0;i<t.size();i++){
            string temp="";
            for(int j=0;j<t.size();j++){
                if(t[i][j]==1)temp+="Q";
                else temp+=".";
            }
            cur.push_back(temp);
        }
        ans.push_back(cur);
    }
    void solve(vector<vector<string>>&ans,vector<vector<int>>&t,int j){
        if(j>=t.size()){
            help(ans,t);
            return ;
        }
        for(int i=0;i<t.size();i++){
            if(check(i,j,t)){
                t[i][j]=1;
                solve(ans,t,j+1);
                t[i][j]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<int>>temp(n,vector<int>(n,0));
       
        solve(ans,temp,0);
        
        return ans;
    }
};