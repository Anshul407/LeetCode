class Solution {
public:
    vector<vector<int>>dp;
    int check(string s,int i,int j){
        if(dp[i][j]!=-1)return dp[i][j];
        int ii=i,jj=j;
        while(i<=j){
            if(s[i]!=s[j])return dp[ii][jj]= 0;
            i++;
            j--;
        }
        return dp[ii][jj]=1;
    }
    void solve(string s,int i,vector<string>&temp,vector<vector<string>>&ans){
        if(i>=s.length()){
            ans.push_back(temp);
            return ;
        }
        for(int j=i;j<s.size();j++){
            if(check(s,i,j)){
                temp.push_back(s.substr(i,j-i+1));
                solve(s,j+1,temp,ans);
                temp.pop_back();
            }
        }
        return ;
    }
    vector<vector<string>> partition(string s) {
        dp.resize(s.size(),vector<int>(s.size(),-1));
        vector<string>temp;
        vector<vector<string>>ans;
        solve(s,0,temp,ans);
        return ans;
    }
};