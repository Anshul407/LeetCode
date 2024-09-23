class Solution {
public:
    int dp[100001];
    map<string,int>mp;
    int solve(string s,int i){
        if(i>s.length())return 0;
        if(dp[i]!=-1)return dp[i];
        int ntk=1+solve(s,i+1);
        int op2=INT_MAX;
        string cur="";
        for(int j=i;j<s.length();j++){
            cur+=s[j];
            if(mp.find(cur)!=mp.end())op2=min(op2,solve(s,j+1));
        }

        return dp[i]= min(op2,ntk);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp,-1,sizeof(dp));
        for(auto i:dictionary){
            mp[i]++;
        }
        return solve(s,0)-1;
    }
};