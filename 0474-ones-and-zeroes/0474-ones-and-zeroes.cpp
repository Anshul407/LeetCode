class Solution {
public:
    int solve(vector<pair<int,int>>&v,int i,vector<vector<vector<int>>>&dp,int m,int n,int size){
        if(i>=size)return 0;
        if(m<0||n<0)return 0;
        // if(m==0&&n==0)return 1;
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        int take=0,ign=0;
        if(v[i].first<=m&&v[i].second<=n){
            take=1+solve(v,i+1,dp,m-v[i].first,n-v[i].second,size);
        }
        ign=solve(v,i+1,dp,m,n,size);

        return dp[i][m][n]=max(ign,take);
    }
    int findMaxForm(vector<string>&strs, int m, int n) {
        vector<pair<int,int>>v;
        for(auto i:strs){
            unordered_map<char,int>mp;
            for(auto j:i){
                mp[j]++;
            }
            v.push_back({mp['0'],mp['1']});

        }
        vector<vector<vector<int>>>dp(v.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(v,0,dp,m,n,v.size());
    }
};